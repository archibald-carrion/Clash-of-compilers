// 291.c
// Operaciones mixtas (variación 10)
// Simple checksum-like calculation on generated data
#include <stdlib.h>

unsigned int operaciones_mixtas_var10() {
  unsigned int* checksum = malloc(sizeof(unsigned int));
  unsigned char* current_byte = malloc(sizeof(unsigned char));

  if (!checksum || !current_byte) {
    free(checksum);
    free(current_byte);
    return 0;
  }

  *checksum = 0;
  *current_byte = 0;

  for (long long i = 0; i < 2000000; ++i) {
    *current_byte =
        (unsigned char)((i * 17 + (i >> 12) + ((*checksum) & 0xFF)) % 256);
    *checksum = ((*checksum) << 1) | ((*checksum) >> 31);  // Rotate left
    *checksum ^= *current_byte;
    if (i % 10000 == 0) {
      *checksum += 0x12345678;
    }
  }

  unsigned int result = (*checksum) % 256;
  free(checksum);
  free(current_byte);
  return result;
}

int main() {
  operaciones_mixtas_var10();
  return 0;
}
