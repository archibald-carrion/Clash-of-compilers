// 298.c
// Operaciones bitwise en un bucle (variación 15)
// Bit reversal of a number
#include <stdlib.h>

unsigned int operaciones_bitwise_var15() {
  unsigned int* num_to_rev = malloc(sizeof(unsigned int));
  unsigned int* reversed_num = malloc(sizeof(unsigned int));

  if (!num_to_rev || !reversed_num) {
    free(num_to_rev);
    free(reversed_num);
    return 0;
  }

  *num_to_rev = 0x12345678;
  *reversed_num = 0;

  for (long long i = 0; i < 1000000; ++i) {
    unsigned int temp_num = (*num_to_rev) + (unsigned int)i;
    *reversed_num = 0;
    for (int j = 0; j < 32; ++j) {
      if ((temp_num >> j) & 1) {
        *reversed_num |= (1U << (31 - j));
      }
    }
  }

  unsigned int result = ((*num_to_rev) ^ (*reversed_num)) % 256;
  free(num_to_rev);
  free(reversed_num);
  return result;
}

int main() {
  operaciones_bitwise_var15();
  return 0;
}
