#!/bin/bash

# Script to compile all C files in ../data/own/ with gcc, execute them, and measure performance
# Each executable will have the same name as the C file (without .c extension) and will be placed in the current directory

# Check if required tools are installed
if ! command -v gcc &> /dev/null; then
    echo "Error: gcc is not installed or not in PATH"
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

echo "Found ${#c_files[@]} C file(s) to compile and benchmark..."
echo "========================================================"
echo

# Create results CSV file
results_csv="benchmark_results_$(date +%Y%m%d_%H%M%S).csv"
echo "filename,exec_size,max_mem_kb,disk_access,avg_time_sec" > "$results_csv"

# Create bin directory if it doesn't exist
bin_dir="./bin"
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
        disk_access=""
        avg_time=""
        # Compile with gcc, output to bin directory
        if gcc "$file" -o "$exe_path" -O2 -lm; then
            # Check if executable exists and is executable
            if [ -x "$exe_path" ]; then
                exec_size=$(ls -lh "$exe_path" | awk '{print $5}')
                # Use /usr/bin/time for timing, memory, and disk access
                if [ -f "/usr/bin/time" ]; then
                    # %e = real time, %M = max mem, %I = fs inputs, %O = fs outputs
                    time_output=$( /usr/bin/time -f "%e,%M,%I,%O" "$exe_path" 2>&1 >/dev/null )
                    IFS=',' read -r real_time max_mem fs_inputs fs_outputs <<< "$time_output"
                    disk_access=$((fs_inputs + fs_outputs))
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
            fi
        fi
        # Write CSV row (empty fields if not available)
        echo "$filename,$exec_size,$max_mem,$disk_access,$avg_time" >> "$results_csv"
    fi
done

echo "========================================================"
echo "Benchmark process completed!"
echo "Results saved to: $results_csv"
echo ""
echo "Summary of executables created:"
for exe in "$bin_dir"/*; do
    if [ -x "$exe" ] && [ ! -d "$exe" ]; then
        size=$(ls -lh "$exe" | awk '{print $5}')
        echo "  $(basename "$exe") ($size)"
    fi
done

echo ""
echo "To view detailed results: cat $results_csv"