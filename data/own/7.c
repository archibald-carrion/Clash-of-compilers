// ==== PROGRAM 7: BINARY FILE OPERATIONS ====
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    float value;
    char name[32];
} Record;

int main() {
    const char* filename = "records.bin";
    Record records[3] = {
        {1, 3.14f, "Alpha"},
        {2, 2.71f, "Beta"},
        {3, 1.41f, "Gamma"}
    };
    
    // Write binary data
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error creating binary file\n");
        return 1;
    }
    
    size_t written = fwrite(records, sizeof(Record), 3, file);
    fclose(file);
    
    printf("Written %zu records to binary file\n", written);
    
    // Read binary data back
    file = fopen(filename, "rb");
    if (!file) {
        printf("Error reading binary file\n");
        return 1;
    }
    
    Record read_records[3];
    size_t read = fread(read_records, sizeof(Record), 3, file);
    fclose(file);
    
    printf("Read %zu records from binary file:\n", read);
    for (int i = 0; i < read; i++) {
        printf("ID: %d, Value: %.2f, Name: %s\n", 
               read_records[i].id, read_records[i].value, read_records[i].name);
    }
    
    remove(filename); // Clean up
    return 0;
}
