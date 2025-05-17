import os
import zstandard as zstd
import json
import tempfile
import subprocess
import hashlib

DATASET_DIR = os.path.join('data', 'train_real_compilable')
OUTPUT_DIR = 'data/refactored'
DISK_PATTERNS = [
    r'open\s*\(', r'os\.remove', r'os\.rename', r'os\.replace', r'os\.rmdir', r'os\.mkdir', r'os\.makedirs',
    r'os\.listdir', r'os\.scandir', r'shutil\.', r'fileinput\.', r'pathlib\.', r'with\s+open', r'os\.walk', r'os\.stat', r'os\.chdir', r'os\.f',
    r'fopen\s*\(', r'fclose\s*\(', r'fread\s*\(', r'fwrite\s*\(', r'remove\s*\(', r'rename\s*\(', r'tmpfile\s*\(', r'tmpnam\s*\(',
    r'freopen\s*\(', r'setbuf\s*\(', r'setvbuf\s*\(', r'fflush\s*\(', r'fseek\s*\(', r'ftell\s*\(', r'rewind\s*\(', r'fgetpos\s*\(',
    r'fsetpos\s*\(', r'fgetc\s*\(', r'fgets\s*\(', r'fputc\s*\(', r'fputs\s*\(', r'fscanf\s*\(', r'fprintf\s*\(', r'fopen64\s*\(',
    r'fcloseall\s*\(', r'fileno\s*\(', r'fdopen\s*\(', r'ftruncate\s*\(', r'open64\s*\(', r'creat\s*\(', r'creat64\s*\(',
    r'unlink\s*\(', r'access\s*\(', r'chdir\s*\(', r'mkdir\s*\(', r'rmdir\s*\(', r'opendir\s*\(', r'readdir\s*\(', r'closedir\s*\(',
    r'stat\s*\(', r'lstat\s*\(', r'fstat\s*\(', r'mkstemp\s*\(', r'mktemp\s*\(', r'perror\s*\(', r'fsync\s*\(', r'fdatasync\s*\('
]
import re
DISK_REGEX = re.compile('|'.join(DISK_PATTERNS))

def disk_weight(code):
    return len(DISK_REGEX.findall(code))

def compile_to_asm(func_def):
    with tempfile.TemporaryDirectory() as tmpdir:
        c_path = os.path.join(tmpdir, 'func.c')
        asm_path = os.path.join(tmpdir, 'func.s')
        with open(c_path, 'w') as f:
            f.write(func_def)
        # Try to compile to assembly
        try:
            result = subprocess.run(['gcc', '-S', c_path, '-o', asm_path], capture_output=True, text=True, timeout=10)
            if result.returncode != 0:
                return None
            with open(asm_path, 'r') as f:
                asm = f.read()
            return asm
        except Exception:
            return None

def process_entry(entry):
    if not (isinstance(entry, dict) and 'text' in entry and 'func_def' in entry['text']):
        return None
    func_def = entry['text']['func_def']
    # Compile to asm
    asm = compile_to_asm(func_def)
    # Disk use analysis
    weight = disk_weight(func_def)
    # IO pair
    io_pair = None
    io_list = entry['text'].get('io')
    if isinstance(io_list, list) and len(io_list) > 0:
        io_pair = io_list[0]
    return {
        'func_def': func_def,
        'asm': asm,
        'disk_weight': weight,
        'io_pair': io_pair
    }

def refactor_file(input_path, output_path):
    with open(input_path, 'rb') as fh:
        dctx = zstd.ZstdDecompressor()
        with dctx.stream_reader(fh) as reader:
            text_stream = reader.read().decode('utf-8')
            entries = []
            for line in text_stream.splitlines():
                try:
                    entry = json.loads(line)
                    processed = process_entry(entry)
                    if processed and processed['asm']:
                        entries.append(processed)
                except Exception:
                    continue
    # Write to new zst file
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    cctx = zstd.ZstdCompressor()
    with open(output_path, 'wb') as f:
        with cctx.stream_writer(f) as writer:
            for entry in entries:
                writer.write((json.dumps(entry) + '\n').encode('utf-8'))

def main():
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    for fname in os.listdir(DATASET_DIR):
        if fname.endswith('.jsonl.zst'):
            in_path = os.path.join(DATASET_DIR, fname)
            out_path = os.path.join(OUTPUT_DIR, fname)
            print(f"Processing {fname} ...")
            refactor_file(in_path, out_path)
    print(f"✅ Refactoring complete. Output in {OUTPUT_DIR}")

if __name__ == '__main__':
    main()
