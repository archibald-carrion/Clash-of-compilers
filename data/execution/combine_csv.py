import os
import pandas as pd
import re
from io import StringIO  # Add this import for StringIO

def process_csv_files(directory):
    """
    Process all CSV files in the specified directory and combine them into a single DataFrame.
    
    Args:
        directory (str): Path to the directory containing CSV files.
        
    Returns:
        DataFrame: Combined data from all CSV files with architecture and compiler info.
    """
    # List to store all dataframes
    all_dfs = []
    
    # Expected columns in the CSV files
    expected_columns = ['filename', 'exec_size', 'max_mem_kb', 'avg_time_sec']
    
    # Regex pattern to extract architecture and compiler from filenames
    pattern = r"(intel|ryzen)_(clang|gcc)"
    
    # Process each file in the directory
    for filename in os.listdir(directory):
        if filename.endswith(".csv"):
            file_path = os.path.join(directory, filename)
            
            # Extract architecture and compiler from filename
            match = re.search(pattern, filename.lower())
            if match:
                architecture = match.group(1)
                compiler = match.group(2)
                
                try:
                    # Read the CSV file, skipping comment lines
                    with open(file_path, 'r') as f:
                        lines = [line for line in f if not line.strip().startswith("//")]
                    
                    if not lines:
                        print(f"Warning: No valid data in {filename}")
                        continue
                        
                    # Read CSV data - Fixed: Use StringIO instead of pd.StringIO
                    df = pd.read_csv(StringIO(''.join(lines)))
                    
                    # Check if all expected columns are present
                    if not all(col in df.columns for col in expected_columns):
                        print(f"Warning: Missing expected columns in {filename}")
                        continue
                    
                    # Drop rows with missing essential data
                    df = df.dropna(subset=expected_columns)
                    
                    if df.empty:
                        print(f"Warning: No valid data after cleaning in {filename}")
                        continue
                    
                    # Add architecture and compiler columns
                    df['architecture'] = architecture
                    df['compiler'] = compiler
                    
                    # Keep only the columns we need
                    df = df[expected_columns + ['architecture', 'compiler']]
                    
                    # Append to the list of dataframes
                    all_dfs.append(df)
                    
                    print(f"Successfully processed: {filename}")
                except Exception as e:
                    print(f"Error processing {filename}: {e}")
    
    # Combine all dataframes
    if all_dfs:
        combined_df = pd.concat(all_dfs, ignore_index=True)
        return combined_df
    else:
        return None

def main():
    """
    Main function to process CSV files and save the combined data.
    """
    # Directory containing the CSV files
    directory = r"c:\Users\Brandon\Desktop\Clash-of-compilers\test_run\data"
    
    print(f"Processing CSV files in: {directory}")
    
    # Process all CSV files
    combined_df = process_csv_files(directory)
    
    if combined_df is not None:
        # Save the combined data to a new CSV file
        output_path = os.path.join(directory, "combined_data.csv")
        combined_df.to_csv(output_path, index=False)
        print(f"Combined data saved to: {output_path}")
        print(f"Total rows in combined data: {len(combined_df)}")
    else:
        print("No data was processed.")

if __name__ == "__main__":
    main()
