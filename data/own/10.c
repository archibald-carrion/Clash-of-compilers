// ==== PROGRAM 10: DIRECTORY OPERATIONS (UNIX/Linux) ====

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    const char* directory = "."; // Current directory
    DIR* dir = opendir(directory);
    
    if (!dir) {
        printf("Error opening directory\n");
        return 1;
    }
    
    struct dirent* entry;
    struct stat file_stat;
    int file_count = 0;
    long total_size = 0;
    
    printf("Directory listing for '%s':\n", directory);
    printf("%-30s %10s %s\n", "Name", "Size", "Type");
    printf("%-30s %10s %s\n", "----", "----", "----");
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char filepath[512];
        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
        
        if (stat(filepath, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) {
                printf("%-30s %10ld %s\n", entry->d_name, file_stat.st_size, "FILE");
                file_count++;
                total_size += file_stat.st_size;
            } else if (S_ISDIR(file_stat.st_mode)) {
                printf("%-30s %10s %s\n", entry->d_name, "-", "DIR");
            }
        }
    }
    
    closedir(dir);
    
    printf("\nSummary: %d files, %ld total bytes\n", file_count, total_size);
    return 0;
}