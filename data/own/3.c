// ==== PROGRAM 3: BASIC FILE EXISTENCE CHECK ====
#include <stdio.h>

int file_exists(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    const char* test_files[] = {"/etc/passwd", "/tmp", "nonexistent.txt", "."};
    int num_files = sizeof(test_files) / sizeof(test_files[0]);
    
    printf("File existence check:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s: %s\n", test_files[i], 
               file_exists(test_files[i]) ? "EXISTS" : "NOT FOUND");
    }
    return 0;
}