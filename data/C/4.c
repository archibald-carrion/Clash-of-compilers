// ==== PROGRAM 4: CREATE AND READ FILE ====
#include <stdio.h>

int main() {
    const char* filename = "temp_numbers.txt";
    
    // Create file with sample data
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error creating file\n");
        return 1;
    }
    
    for (int i = 1; i <= 5; i++) {
        fprintf(file, "%d\n", i * 10);
    }
    fclose(file);
    
    // Read and count lines
    file = fopen(filename, "r");
    if (!file) {
        printf("Error reading file\n");
        return 1;
    }
    
    int lines = 0, ch;
    printf("File contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
        if (ch == '\n') lines++;
    }
    fclose(file);
    
    printf("Total lines: %d\n", lines);
    remove(filename); // Clean up
    return 0;
}