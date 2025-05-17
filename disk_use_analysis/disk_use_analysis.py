import os
import zstandard as zstd
import json
import csv
import hashlib
import re

DATASET_DIR = os.path.join('data', 'train_real_compilable')
OUTPUT_CSV = 'disk_use_analysis/disk_use_report.csv'


# Patterns for disk-intensive operations (Python and C)
DISK_PATTERNS = [
    # Python
    r'open\s*\(',
    r'os\.remove', r'os\.rename', r'os\.replace', r'os\.rmdir', r'os\.mkdir', r'os\.makedirs',
    r'os\.listdir', r'os\.scandir', r'shutil\.', r'fileinput\.', r'pathlib\.', r'with\s+open',
    r'os\.walk', r'os\.stat', r'os\.chdir', r'os\.f',
    # C/C++
    r'fopen\s*\(', r'fclose\s*\(', r'fread\s*\(', r'fwrite\s*\(', r'remove\s*\(', r'rename\s*\(',
    r'tmpfile\s*\(', r'tmpnam\s*\(', r'freopen\s*\(', r'setbuf\s*\(', r'setvbuf\s*\(',
    r'fflush\s*\(', r'fseek\s*\(', r'ftell\s*\(', r'rewind\s*\(', r'fgetpos\s*\(', r'fsetpos\s*\(',
    r'fgetc\s*\(', r'fgets\s*\(', r'fputc\s*\(', r'fputs\s*\(', r'fscanf\s*\(', r'fprintf\s*\(',
    r'fopen64\s*\(', r'fcloseall\s*\(', r'fileno\s*\(', r'fdopen\s*\(', r'ftruncate\s*\(',
    r'open64\s*\(', r'creat\s*\(', r'creat64\s*\(', r'unlink\s*\(', r'access\s*\(',
    r'chdir\s*\(', r'mkdir\s*\(', r'rmdir\s*\(', r'opendir\s*\(', r'readdir\s*\(', r'closedir\s*\(',
    r'stat\s*\(', r'lstat\s*\(', r'fstat\s*\(', r'mkstemp\s*\(', r'mktemp\s*\(',
    r'perror\s*\(', r'fsync\s*\(', r'fdatasync\s*\(',
]

# Compile regex
DISK_REGEX = re.compile('|'.join(DISK_PATTERNS))

def disk_weight(code):
    """Assign a weight based on number of disk operations found."""
    return len(DISK_REGEX.findall(code))

def unique_function_id(code, meta=None):
    """Generate a unique id for a function (hash of code, optionally with meta)."""
    base = code
    if meta:
        base += str(meta)
    return hashlib.sha256(base.encode('utf-8')).hexdigest()

def analyze_file(filepath, writer):
    with open(filepath, 'rb') as fh:
        dctx = zstd.ZstdDecompressor()
        with dctx.stream_reader(fh) as reader:
            text_stream = reader.read().decode('utf-8')
            for line in text_stream.splitlines():
                try:
                    entry = json.loads(line)
                    # Only process entries with 'text' and 'func_def'
                    if not (isinstance(entry, dict) and 'text' in entry and 'func_def' in entry['text']):
                        continue
                    func_def = entry['text']['func_def']
                    func_name = entry['text'].get('fname')
                    if not func_name:
                        # Try to extract from func_def
                        parts = func_def.split('(')[0].strip().split()
                        func_name = parts[-1] if parts else 'unknown'
                    # Unique identifier: function name + hash of func_def
                    hash_object = hashlib.md5(func_def.encode())
                    hash_suffix = hash_object.hexdigest()[:6]
                    identifier = f"{func_name}_{hash_suffix}"
                    weight = disk_weight(func_def)
                    writer.writerow({'function_id': identifier, 'disk_weight': weight})
                except Exception as e:
                    continue

def main():
    os.makedirs('disk_use_analysis', exist_ok=True)
    with open(OUTPUT_CSV, 'w', newline='', encoding='utf-8') as csvfile:
        fieldnames = ['function_id', 'disk_weight']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        for fname in os.listdir(DATASET_DIR):
            if fname.endswith('.jsonl.zst'):
                analyze_file(os.path.join(DATASET_DIR, fname), writer)
print(f"✅ Disk use analysis complete. Results saved to {OUTPUT_CSV}")

if __name__ == '__main__':
    main()
