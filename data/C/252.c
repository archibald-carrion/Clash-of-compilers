// 252.c
// Manipulación de array (variación 8)
#include <stdlib.h>

#define ARRAY_SIZE_252 4096

int manipulacion_array_var8() {
  unsigned char* array = malloc(ARRAY_SIZE_252 * sizeof(unsigned char));
  if (!array) return 0;

  unsigned int* counts = malloc(256 * sizeof(unsigned int));
  if (!counts) {
    free(array);
    return 0;
  }

  // Initialize counts array
  for (int i = 0; i < 256; ++i) counts[i] = 0;

  for (int iter = 0; iter < 50; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_252; ++i) {
      array[i] = (unsigned char)((i * iter * 13 + 12345) % 256);
    }
    for (int i = 0; i < ARRAY_SIZE_252; ++i) {
      counts[array[i]]++;
    }
  }

  long long final_val = 0;
  for (int i = 0; i < 256; ++i) final_val += counts[i] * i;

  int result = (int)(final_val % 256);
  free(array);
  free(counts);
  return result;
}

int main() {
  manipulacion_array_var8();
  return 0;
}
