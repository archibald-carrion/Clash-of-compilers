#!/bin/bash

# Check if required tools are installed
if ! command -v clang &> /dev/null; then
    echo "Error: clang is not installed or not in PATH"
    exit 1
fi

if ! command -v time &> /dev/null; then
    echo "Error: time command is not available"
    exit 1
fi

# Check for high precision timing tools
if ! command -v bc &> /dev/null; then
    echo "Warning: bc (calculator) not found. High precision math may be limited."
fi

if ! command -v iostat &> /dev/null && ! command -v iotop &> /dev/null; then
    echo "Warning: Neither iostat nor iotop found. Disk I/O monitoring may be limited."
fi

# Find C files in ../data/own/
c_files=(../data/own/*.c)
if [ ! -e "${c_files[0]}" ]; then
    echo "No C files found in ../data/own/"
    exit 0
fi

echo "Found ${#c_files[@]} C file(s) to compile with clang and benchmark..."
echo "========================================================"
echo

# Create results CSV file
results_csv="benchmark_results_clang_$(date +%Y%m%d_%H%M%S).csv"
echo "filename,exec_size,max_mem_kb,avg_time_sec" > "$results_csv"

# Create bin directory if it doesn't exist
bin_dir="./bin_clang" # Using a different bin directory for clang executables
if [ ! -d "$bin_dir" ]; then
    mkdir "$bin_dir"
fi

# Compile and benchmark each C file
for file in "${c_files[@]}"; do
    if [ -f "$file" ]; then
        # Get filename without path and extension
        filename=$(basename -- "$file")
        basename_noext="${filename%.c}"
        exe_path="$bin_dir/$basename_noext"
        exec_size=""
        max_mem=""
        avg_time=""
        # Compile with clang, output to bin_clang directory
        if clang "$file" -o "$exe_path" -O2 -lm; then
            # Check if executable exists and is executable
            if [ -x "$exe_path" ]; then
                exec_size=$(ls -lh "$exe_path" | awk '{print $5}')
                # Use /usr/bin/time for timing, memory, and disk access
                if [ -f "/usr/bin/time" ]; then
                    # %e = real time, %M = max mem, %I = fs inputs, %O = fs outputs
                    time_output=$( /usr/bin/time -f "%e,%M,%I,%O" "$exe_path" 2>&1 >/dev/null )
                    IFS=',' read -r real_time max_mem fs_inputs fs_outputs <<< "$time_output"
                else
                    # Fallback: use date for real time only
                    start_time=$(date +%s.%N)
                    "$exe_path" > /dev/null 2>&1
                    end_time=$(date +%s.%N)
                    real_time=$(echo "$end_time - $start_time" | bc -l 2>/dev/null || awk "BEGIN {print $end_time - $start_time}")
                fi
                # Average of 10 runs (real time)
                total_time=0
                runs=10
                for ((i=1; i<=runs; i++)); do
                    start_time=$(date +%s.%N)
                    "$exe_path" > /dev/null 2>&1
                    end_time=$(date +%s.%N)
                    run_time=$(echo "$end_time - $start_time" | bc -l 2>/dev/null || awk "BEGIN {print $end_time - $start_time}")
                    total_time=$(echo "$total_time + $run_time" | bc -l 2>/dev/null || awk "BEGIN {print $total_time + $run_time}")
                done
                avg_time=$(echo "scale=9; $total_time / $runs" | bc -l 2>/dev/null || awk "BEGIN {printf \"%.9f\", $total_time / $runs}")
            else
                echo "Error: Could not execute $exe_path"
            fi
        else
            echo "Error: Compilation failed for $file with clang"
        fi
        # Write CSV row (empty fields if not available)
        echo "$filename,$exec_size,$max_mem,$avg_time" >> "$results_csv"
    fi
done

echo "========================================================"
echo "Benchmark process completed!"
echo "Results saved to: $results_csv"
echo ""
echo "Summary of executables created in $bin_dir:"
for exe in "$bin_dir"/*; do
    if [ -x "$exe" ] && [ ! -d "$exe" ]; then
        size=$(ls -lh "$exe" | awk '{print $5}')
        echo "  $(basename "$exe") ($size)"
    fi
done

echo ""
echo "To view detailed results: cat $results_csv"
