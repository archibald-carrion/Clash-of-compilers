import os
import zstandard as zstd
import json

REF_DIR = 'data/refactored'

def test_refactored_file(filepath):
    with open(filepath, 'rb') as fh:
        dctx = zstd.ZstdDecompressor()
        with dctx.stream_reader(fh) as reader:
            text_stream = reader.read().decode('utf-8')
            for i, line in enumerate(text_stream.splitlines()):
                entry = json.loads(line)
                assert isinstance(entry.get('func_def'), str) and entry['func_def'].strip(), f"Missing or empty func_def at line {i}"
                assert isinstance(entry.get('asm'), str) and entry['asm'].strip(), f"Missing or empty asm at line {i}"
                assert isinstance(entry.get('disk_weight'), int), f"disk_weight not int at line {i}"
                io_pair = entry.get('io_pair')
                if io_pair is not None:
                    assert isinstance(io_pair, dict), f"io_pair not dict at line {i}"
                    assert 'input' in io_pair and 'output' in io_pair, f"io_pair missing keys at line {i}"
    print(f"{os.path.basename(filepath)}: OK")

def main():
    for fname in os.listdir(REF_DIR):
        if fname.endswith('.jsonl.zst'):
            test_refactored_file(os.path.join(REF_DIR, fname))

if __name__ == '__main__':
    main()
