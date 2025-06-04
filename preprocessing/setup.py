#!/usr/bin/env python3
"""
ExeBench Dataset Processor

A tool for downloading, extracting, and processing the ExeBench dataset.
Extracts C functions with I/O pairs into organized directory structures.
"""

import hashlib
import json
import os
import shutil
import tarfile
from pathlib import Path
from typing import Dict, List, Tuple, Optional
import logging

import requests
import zstandard as zstd

# Configure logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


class ExeBenchProcessor:
    """Main processor for ExeBench dataset operations."""
    
    def __init__(self, data_dir: str = "data"):
        self.data_dir = Path(data_dir)
        self.data_dir.mkdir(exist_ok=True)
        
    def process_dataset(self, url: str = None) -> None:
        """Complete pipeline: download, extract, and process dataset."""
        if url is None:
            url = "https://huggingface.co/datasets/jordiae/exebench/resolve/main/test_real.tar.gz"
            
        # Step 1: Download and extract
        archive_path = self._download_dataset(url)
        extract_dir = self._extract_archive(archive_path)
        
        # Step 2: Process all JSONL files
        self._process_all_jsonl_files(extract_dir)
        
        logger.info("✅ Dataset processing complete!")
    
    def _download_dataset(self, url: str) -> Path:
        """Download dataset from URL."""
        output_file = self.data_dir / "test_real.tar.gz"
        
        logger.info("📥 Downloading dataset...")
        try:
            response = requests.get(url, stream=True, timeout=30)
            response.raise_for_status()
            
            with open(output_file, 'wb') as f:
                for chunk in response.iter_content(chunk_size=8192):
                    if chunk:
                        f.write(chunk)
                        
            logger.info("✅ Download complete")
            return output_file
            
        except requests.RequestException as e:
            logger.error(f"❌ Download failed: {e}")
            raise
    
    def _extract_archive(self, archive_path: Path) -> Path:
        """Extract tar.gz archive and organize files."""
        extract_dir = self.data_dir / "test_real"
        extract_dir.mkdir(exist_ok=True)
        
        logger.info("📦 Extracting archive...")
        
        # Use temporary directory for extraction
        tmp_dir = self.data_dir / "tmp_extract"
        tmp_dir.mkdir(exist_ok=True)
        
        try:
            with tarfile.open(archive_path, "r:gz") as tar:
                tar.extractall(path=tmp_dir)
            
            # Move .jsonl.zst files to final location
            self._move_jsonl_files(tmp_dir, extract_dir)
            
            # Cleanup
            shutil.rmtree(tmp_dir)
            archive_path.unlink()  # Remove downloaded archive
            
            logger.info("✅ Extraction complete")
            return extract_dir
            
        except (tarfile.TarError, OSError) as e:
            logger.error(f"❌ Extraction failed: {e}")
            if tmp_dir.exists():
                shutil.rmtree(tmp_dir)
            raise
    
    def _move_jsonl_files(self, source_dir: Path, target_dir: Path) -> None:
        """Move .jsonl.zst files from nested structure to target directory."""
        for file_path in source_dir.rglob("*.jsonl.zst"):
            target_path = target_dir / file_path.name
            shutil.move(str(file_path), str(target_path))
    
    def _process_all_jsonl_files(self, extract_dir: Path) -> None:
        """Process all JSONL files in the extraction directory."""
        jsonl_files = list(extract_dir.glob("*.jsonl.zst"))
        
        if not jsonl_files:
            logger.warning("No JSONL files found to process")
            return
            
        logger.info(f"Found {len(jsonl_files)} JSONL files to process")
        
        for jsonl_file in jsonl_files:
            output_dir = extract_dir / f"{jsonl_file.stem}_io_pairs"
            processor = FunctionExtractor(output_dir)
            
            logger.info(f"Processing {jsonl_file.name}...")
            functions_count, pairs_count = processor.extract_functions_with_io_pairs(jsonl_file)
            
            logger.info(f"  - Functions: {functions_count}, I/O pairs: {pairs_count}")


class FunctionExtractor:
    """Handles extraction of C functions with I/O pairs from JSONL files."""
    
    def __init__(self, output_dir: Path):
        self.output_dir = Path(output_dir)
        self.functions_dir = self.output_dir / "functions"
        self.io_pairs_dir = self.output_dir / "io_pairs"
        
        # Create directory structure
        self.output_dir.mkdir(exist_ok=True)
        self.functions_dir.mkdir(exist_ok=True)
        self.io_pairs_dir.mkdir(exist_ok=True)
    
    def extract_functions_with_io_pairs(self, jsonl_path: Path) -> Tuple[int, int]:
        """
        Extract C functions with I/O pairs from compressed JSONL file.
        
        Returns:
            Tuple of (functions_extracted, io_pairs_created)
        """
        functions_extracted = 0
        io_pairs_created = 0
        metadata = []
        
        try:
            for entry in self._read_jsonl_entries(jsonl_path):
                result = self._process_entry(entry)
                if result:
                    function_metadata = result
                    metadata.extend(function_metadata)
                    functions_extracted += 1
                    io_pairs_created += len(function_metadata)
            
            # Write metadata and summary
            self._write_metadata(metadata)
            self._write_summary(functions_extracted, io_pairs_created)
            
            return functions_extracted, io_pairs_created
            
        except Exception as e:
            logger.error(f"❌ Failed to process {jsonl_path.name}: {e}")
            raise
    
    def _read_jsonl_entries(self, jsonl_path: Path):
        """Generator to read entries from compressed JSONL file."""
        with open(jsonl_path, 'rb') as compressed_file:
            dctx = zstd.ZstdDecompressor()
            
            with dctx.stream_reader(compressed_file) as reader:
                text_stream = reader.read().decode('utf-8')
                
                for line_num, line in enumerate(text_stream.splitlines(), 1):
                    line = line.strip()
                    if not line:
                        continue
                        
                    try:
                        yield json.loads(line)
                    except json.JSONDecodeError as e:
                        logger.warning(f"Failed to parse JSON at line {line_num}: {e}")
                        continue
    
    def _process_entry(self, entry: Dict) -> Optional[List[Dict]]:
        """Process a single JSONL entry and extract function with I/O pairs."""
        text = entry.get('text', {})
        if not text:
            return None
            
        func_def = text.get('func_def')
        real_io_pairs = text.get('real_io_pairs')
        
        # Only process functions that have I/O pairs
        if not (func_def and real_io_pairs):
            return None
            
        # Extract function metadata
        func_info = FunctionInfo(
            name=text.get('fname', 'unknown'),
            definition=func_def,
            signature=text.get('signature', []),
            path=text.get('path', 'unknown'),
            io_pairs=real_io_pairs
        )
        
        return self._create_function_files(func_info)
    
    def _create_function_files(self, func_info: 'FunctionInfo') -> List[Dict]:
        """Create function and I/O pair files for a given function."""
        unique_id = self._generate_unique_id(func_info)
        metadata_list = []
        
        for io_idx, io_pair in enumerate(func_info.io_pairs):
            pair_id = f"{unique_id}_{io_idx}"
            
            # Create function file
            func_filename = f"function_{pair_id}.c"
            self._write_function_file(func_filename, func_info, unique_id, io_idx)
            
            # Create I/O pair file
            io_filename = f"io_{pair_id}.json"
            self._write_io_pair_file(io_filename, func_info, unique_id, io_idx, io_pair, func_filename)
            
            # Store metadata
            metadata_list.append({
                "unique_id": unique_id,
                "pair_id": pair_id,
                "function_name": func_info.name,
                "source_path": func_info.path,
                "signature": func_info.signature,
                "function_file": func_filename,
                "io_file": io_filename,
                "pair_index": io_idx,
                "total_pairs": len(func_info.io_pairs)
            })
        
        return metadata_list
    
    def _generate_unique_id(self, func_info: 'FunctionInfo') -> str:
        """Generate unique ID for function based on content and path."""
        unique_content = f"{func_info.path}:{func_info.name}:{func_info.definition}"
        return hashlib.md5(unique_content.encode()).hexdigest()[:12]
    
    def _write_function_file(self, filename: str, func_info: 'FunctionInfo', 
                           unique_id: str, io_idx: int) -> None:
        """Write C function to file with metadata header."""
        filepath = self.functions_dir / filename
        
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(f"// Function: {func_info.name}\n")
            f.write(f"// Signature: {' '.join(func_info.signature) if func_info.signature else 'unknown'}\n")
            f.write(f"// Source: {func_info.path}\n")
            f.write(f"// Unique ID: {unique_id}\n")
            f.write(f"// I/O Pair Index: {io_idx}\n")
            f.write(f"// Total I/O Pairs: {len(func_info.io_pairs)}\n\n")
            f.write(func_info.definition.strip() + '\n')
    
    def _write_io_pair_file(self, filename: str, func_info: 'FunctionInfo', 
                          unique_id: str, io_idx: int, io_pair: Dict, func_filename: str) -> None:
        """Write I/O pair data to JSON file."""
        filepath = self.io_pairs_dir / filename
        
        io_data = {
            "function_id": unique_id,
            "function_name": func_info.name,
            "pair_index": io_idx,
            "input": io_pair.get('input', {}),
            "output": io_pair.get('output', {}),
            "signature": func_info.signature,
            "function_file": func_filename
        }
        
        with open(filepath, 'w', encoding='utf-8') as f:
            json.dump(io_data, f, indent=2)
    
    def _write_metadata(self, metadata: List[Dict]) -> None:
        """Write metadata file with all function information."""
        metadata_path = self.output_dir / "metadata.json"
        
        with open(metadata_path, 'w', encoding='utf-8') as f:
            json.dump(metadata, f, indent=2)
    
    def _write_summary(self, functions_extracted: int, io_pairs_created: int) -> None:
        """Write summary file with extraction statistics."""
        summary_path = self.output_dir / "summary.txt"
        
        with open(summary_path, 'w', encoding='utf-8') as f:
            f.write("Function Extraction Summary\n")
            f.write("==========================\n\n")
            f.write(f"Functions extracted: {functions_extracted}\n")
            f.write(f"I/O pairs created: {io_pairs_created}\n")
            f.write(f"Functions directory: {self.functions_dir}\n")
            f.write(f"I/O pairs directory: {self.io_pairs_dir}\n")
            f.write(f"Metadata file: {self.output_dir / 'metadata.json'}\n\n")
            f.write("Structure:\n")
            f.write("- function_<ID>.c: Contains the C function\n")
            f.write("- io_<ID>.json: Contains corresponding I/O example\n")
            f.write("- metadata.json: Contains all function metadata\n")


class FunctionInfo:
    """Data class to hold function information."""
    
    def __init__(self, name: str, definition: str, signature: List[str], 
                 path: str, io_pairs: List[Dict]):
        self.name = name
        self.definition = definition
        self.signature = signature
        self.path = path
        self.io_pairs = io_pairs

def main():
    """Main entry point."""
    try:
        processor = ExeBenchProcessor()
        processor.process_dataset()
    except Exception as e:
        logger.error(f"❌ Processing failed: {e}")
        raise

if __name__ == "__main__":
    main()