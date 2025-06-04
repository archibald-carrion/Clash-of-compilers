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

# Create results file
results_file="benchmark_results_$(date +%Y%m%d_%H%M%S).txt"
echo "Benchmark Results - $(date)" > "$results_file"
echo "=======================================================" >> "$results_file"

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
        echo "Processing: $filename"
        echo "----------------------------------------"
        echo "Processing: $filename" >> "$results_file"
        echo "----------------------------------------" >> "$results_file"
        # Compile with gcc, output to bin directory
        echo "Compiling $file -> $exe_path"
        if gcc "$file" -o "$exe_path" -O2; then
            echo "✓ Successfully compiled $file"
            echo "✓ Successfully compiled $file" >> "$results_file"
            # Check if executable exists and is executable
            if [ -x "$exe_path" ]; then
                echo "Executing and measuring performance..."
                echo "Executing and measuring performance..." >> "$results_file"
                # Get initial disk stats (if available)
                if command -v iostat &> /dev/null; then
                    iostat_before=$(iostat -d 1 1 | tail -n +4)
                fi
                echo "Execution output:" >> "$results_file"
                echo "Running with high-precision timing..."
                # Method 1: Use /usr/bin/time with format for microsecond precision
                if [ -f "/usr/bin/time" ]; then
                    echo "Detailed timing (microsecond precision):" >> "$results_file"
                    /usr/bin/time -f "Real time: %e seconds (%E elapsed)\nUser CPU time: %U seconds\nSystem CPU time: %S seconds\nCPU usage: %P\nMax memory: %M KB\nPage faults: %F major, %R minor\nFile system inputs: %I\nFile system outputs: %O" "$exe_path" 2>&1 | tee -a "$results_file"
                    echo "" >> "$results_file"
                else
                    echo "Basic timing:" >> "$results_file"
                    { time "$exe_path"; } 2>&1 | tee -a "$results_file"
                    echo "" >> "$results_file"
                fi
                # Method 2: Additional high-precision timing with date (nanosecond precision)
                echo "Nanosecond precision measurement:" >> "$results_file"
                start_time=$(date +%s.%N)
                "$exe_path" > /dev/null 2>&1
                end_time=$(date +%s.%N)
                execution_time=$(echo "$end_time - $start_time" | bc -l 2>/dev/null || awk "BEGIN {print $end_time - $start_time}")
                printf "Execution time: %.9f seconds (%.3f milliseconds)\n" "$execution_time" "$(echo "$execution_time * 1000" | bc -l 2>/dev/null || awk "BEGIN {print $execution_time * 1000}")" | tee -a "$results_file"
                # Method 3: Multiple runs for average (for very fast programs)
                echo "Average of 10 runs:" >> "$results_file"
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
                printf "Average execution time: %.9f seconds (%.3f milliseconds)\n" "$avg_time" "$(echo "$avg_time * 1000" | bc -l 2>/dev/null || awk "BEGIN {print $avg_time * 1000}")" | tee -a "$results_file"
                # Get disk stats after execution (if available)
                if command -v iostat &> /dev/null; then
                    iostat_after=$(iostat -d 1 1 | tail -n +4)
                    echo "Disk I/O Stats:" >> "$results_file"
                    echo "Before execution:" >> "$results_file"
                    echo "$iostat_before" >> "$results_file"
                    echo "After execution:" >> "$results_file"
                    echo "$iostat_after" >> "$results_file"
                fi
                # Get file size of executable
                exec_size=$(ls -lh "$exe_path" | awk '{print $5}')
                echo "Executable size: $exec_size"
                echo "Executable size: $exec_size" >> "$results_file"
                # Check for core dumps or other files created
                if ls core* &> /dev/null 2>&1; then
                    echo "Warning: Core dump files detected"
                    echo "Warning: Core dump files detected" >> "$results_file"
                fi
            else
                echo "✗ Executable not found or not executable"
                echo "✗ Executable not found or not executable" >> "$results_file"
            fi
        else
            echo "✗ Failed to compile $file"
            echo "✗ Failed to compile $file" >> "$results_file"
        fi
        echo ""
        echo "=======================================================" >> "$results_file"
        echo ""
    fi
done

echo "========================================================"
echo "Benchmark process completed!"
echo "Results saved to: $results_file"
echo ""
echo "Summary of executables created:"
for exe in "$bin_dir"/*; do
    if [ -x "$exe" ] && [ ! -d "$exe" ]; then
        size=$(ls -lh "$exe" | awk '{print $5}')
        echo "  $(basename "$exe") ($size)"
    fi
done

echo ""
echo "To view detailed results: cat $results_file"