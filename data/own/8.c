// ==== PROGRAM 8: FILE COPY OPERATIONS ====
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* source = "source.txt";
    const char* dest = "destination.txt";
    
    // Create source file
    FILE* file = fopen(source, "w");
    if (!file) {
        printf("Error creating source file\n");
        return 1;
    }
    
    fprintf(file, "This is a test file for copying.\n");
    fprintf(file, "It contains multiple lines.\n");
    fprintf(file, "Each line will be copied to destination.\n");
    fclose(file);
    
    // Copy file
    FILE* src = fopen(source, "rb");
    FILE* dst = fopen(dest, "wb");
    
    if (!src || !dst) {
        printf("Error opening files for copy\n");
        if (src) fclose(src);
        if (dst) fclose(dst);
        return 1;
    }
    
    char buffer[256];
    size_t bytes;
    size_t total_copied = 0;
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
        total_copied += bytes;
    }
    
    fclose(src);
    fclose(dst);
    
    printf("Copied %zu bytes from %s to %s\n", total_copied, source, dest);
    
    // Verify copy
    file = fopen(dest, "r");
    if (file) {
        printf("Destination file contents:\n");
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    }
    
    remove(source); // Clean up
    remove(dest);
    return 0;
}