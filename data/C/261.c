// 261.c
// Operaciones bitwise en un bucle (variación 8)
#include <stdlib.h>

unsigned int operaciones_bitwise_var8() {
  unsigned int* data = malloc(sizeof(unsigned int));
  if (!data) return 0;

  *data = 0xFEEDFACE;
  for (long long i = 0; i < 2300000; ++i) {
    *data = ((*data) & 0xFFFFFF00) | (((*data) + (unsigned int)i) % 0xFF);
    *data = ((*data) >> (i % 4)) | ((*data) << (32 - (i % 4)));
  }

  unsigned int result = (*data) % 256;
  free(data);
  return result;
}

int main() {
  operaciones_bitwise_var8();
  return 0;
}
