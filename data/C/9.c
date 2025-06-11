// ==== PROGRAM 9: SEARCH AND REPLACE IN FILE ====

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char* filename = "text_file.txt";
    
    // Create file with sample text
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error creating file\n");
        return 1;
    }
    
    fprintf(file, "klaatu \n");
    fprintf(file, "barada \n");
    fprintf(file, "nikto \n");
    fclose(file);
    
    // Read entire file
    file = fopen(filename, "r");
    if (!file) {
        printf("Error reading file\n");
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    
    char* content = malloc(size + 1);
    if (!content) {
        printf("Memory allocation error\n");
        fclose(file);
        return 1;
    }
    
    fread(content, 1, size, file);
    content[size] = '\0';
    fclose(file);
    
    printf("Original content:\n%s\n", content);
    
    // Simple search and replace (first occurrence)
    char* pos = strstr(content, "world");
    if (pos) {
        printf("Found 'world' at position %ld\n", pos - content);
        
        // Create new content with replacement
        char* new_content = malloc(size + 10); // Extra space for longer replacement
        if (new_content) {
            strncpy(new_content, content, pos - content);
            new_content[pos - content] = '\0';
            strcat(new_content, "universe");
            strcat(new_content, pos + 5); // Skip "world"
            
            // Write back to file
            file = fopen(filename, "w");
            if (file) {
                fprintf(file, "%s", new_content);
                fclose(file);
                printf("Replacement completed.\n");
                
                // Show result
                printf("New content:\n%s\n", new_content);
            }
            free(new_content);
        }
    }
    
    free(content);
    remove(filename); // Clean up
    return 0;
}
