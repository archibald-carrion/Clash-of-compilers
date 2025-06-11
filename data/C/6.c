// ==== PROGRAM 6: CALCULATE SUM FROM FILE ====
#include <stdio.h>

int main() {
    const char* filename = "numbers_sum.txt";
    int numbers[] = {15, 25, 35, 45, 55};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    // Create file with numbers
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error creating file\n");
        return 1;
    }
    
    printf("Numbers written to file: ");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", numbers[i]);
        printf("%d ", numbers[i]);
    }
    fclose(file);
    
    // Calculate sum from file
    file = fopen(filename, "r");
    if (!file) {
        printf("Error reading file\n");
        return 1;
    }
    
    long sum = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        sum += num;
    }
    fclose(file);
    
    printf("\nSum from file: %ld\n", sum);
    remove(filename); // Clean up
    return 0;
}