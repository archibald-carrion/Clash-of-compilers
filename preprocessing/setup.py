import requests
import tarfile
import os
import shutil

data_dir = "data"
if not os.path.exists(data_dir):
    os.makedirs(data_dir)

# URL of the dataset
url = "https://huggingface.co/datasets/jordiae/exebench/resolve/main/train_real_compilable.tar.gz"
output_file = os.path.join(data_dir, "train_real_compilable.tar.gz")
extract_dir = os.path.join(data_dir, "train_real_compilable")

# Download the file
print("📥 Downloading dataset...")
response = requests.get(url, stream=True)
with open(output_file, 'wb') as f:
    for chunk in response.iter_content(chunk_size=8192):
        f.write(chunk)
print("✅ Download complete.")

# Extract the tar.gz file
print("📦 Extracting archive...")
if not os.path.exists(extract_dir):
    os.makedirs(extract_dir)

# Extract to a temporary directory first
tmp_extract_dir = os.path.join(data_dir, "tmp_extract")
if not os.path.exists(tmp_extract_dir):
    os.makedirs(tmp_extract_dir)

with tarfile.open(output_file, "r:gz") as tar:
    tar.extractall(path=tmp_extract_dir)

# Move .jsonl.zst files from nested folder to extract_dir
for root, dirs, files in os.walk(tmp_extract_dir):
    for file in files:
        if file.endswith(".jsonl.zst"):
            src = os.path.join(root, file)
            dst = os.path.join(extract_dir, file)
            shutil.move(src, dst)

# Clean up temporary extraction directory
shutil.rmtree(tmp_extract_dir)

print("✅ Extraction complete.")

# Optional: remove the .tar.gz file
# os.remove(output_file)
