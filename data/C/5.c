// ==== PROGRAM 5: WRITE ARRAY TO FILE ====
#include <stdio.h>

int main() {
    const char* filename = "array_output.txt";
    int arr[] = {100, 200, 300, 400, 500};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error creating file\n");
        return 1;
    }
    
    printf("Writing array to file: ");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", arr[i]);
        printf("%d ", arr[i]);
    }
    fclose(file);
    
    printf("\nArray written to %s successfully\n", filename);
    
    // Verify by reading back
    file = fopen(filename, "r");
    if (file) {
        printf("Verification - file contains:\n");
        int num;
        while (fscanf(file, "%d", &num) == 1) {
            printf("%d ", num);
        }
        printf("\n");
        fclose(file);
    }
    
    remove(filename); // Clean up
    return 0;
}