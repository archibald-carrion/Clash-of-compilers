// 300.c
// Manipulación de array (variación 16)
#include <stdlib.h>
#define ARRAY_SIZE_300 2048

unsigned int manipulacion_array_var16() {
  unsigned char* image = malloc(ARRAY_SIZE_300 * sizeof(unsigned char));
  if (!image) return 0;

  unsigned int* histogram = malloc(256 * sizeof(unsigned int));
  if (!histogram) {
    free(image);
    return 0;
  }

  for (int iter = 0; iter < 25; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_300; ++i) {
      image[i] =
          (unsigned char)(((iter + 1) * (i * i) + i * 17 + (iter * 31)) % 256);
    }
    for (int i = 0; i < 256; ++i) histogram[i] = 0;  // Reset histogram
    for (int i = 0; i < ARRAY_SIZE_300; ++i) {
      histogram[image[i]]++;
    }
  }

  unsigned int* max_freq = malloc(sizeof(unsigned int));
  if (!max_freq) {
    free(image);
    free(histogram);
    return 0;
  }
  *max_freq = 0;

  for (int i = 0; i < 256; ++i)
    if (histogram[i] > *max_freq) *max_freq = histogram[i];

  unsigned int result = (*max_freq) % 256;
  free(image);
  free(histogram);
  free(max_freq);
  return result;
}

int main() {
  manipulacion_array_var16();
  return 0;
}
