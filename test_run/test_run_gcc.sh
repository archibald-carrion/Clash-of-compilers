#!/bin/bash

# Script to compile all C files in ../data/own/ with gcc
# Each executable will have the same name as the C file (without .c extension) and will be placed in the current directory

# Check if gcc is installed
if ! command -v gcc &> /dev/null; then
    echo "Error: gcc is not installed or not in PATH"
    exit 1
fi

# Find C files in ../data/own/
c_files=(../data/own/*.c)
if [ ! -e "${c_files[0]}" ]; then
    echo "No C files found in ../data/own/"
    exit 0
fi

echo "Found ${#c_files[@]} C file(s) to compile..."
echo

# Compile each C file from ../data/own/
for file in "${c_files[@]}"; do
    if [ -f "$file" ]; then
        # Get filename without path and extension
        filename=$(basename -- "$file")
        basename_noext="${filename%.c}"
        echo "Compiling $file -> $basename_noext"
        # Compile with gcc, output to current directory
        if gcc "$file" -o "$basename_noext"; then
            echo "✓ Successfully compiled $file"
        else
            echo "✗ Failed to compile $file"
        fi
        echo
    fi
done

echo "Compilation process completed!"
echo "Executables created:"
ls -la | grep -E '^-rwx.*[^.c]$' | awk '{print $9}' | grep -v '\.c$' | while read exec; do
    if [ -x "$exec" ] && [ ! -d "$exec" ]; then
        echo "  $exec"
    fi

done