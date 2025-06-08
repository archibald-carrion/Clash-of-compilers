// 262.c
// Operaciones bitwise en un bucle (variación 9)
#include <stdlib.h>

unsigned long long operaciones_bitwise_var9() {
  unsigned long long* state = malloc(sizeof(unsigned long long));
  if (!state) return 0;

  *state = 0xABCDEF0123456789ULL;
  for (long long i = 0; i < 1700000; ++i) {
    *state += 0x9E3779B97F4A7C15ULL;  // Constant from TEA algorithm
    unsigned long long temp = *state;
    temp = (temp ^ (temp >> 30)) * 0xBF58476D1CE4E5B9ULL;
    temp = (temp ^ (temp >> 27)) * 0x94D049BB133111EBULL;
    *state ^= temp >> 31;
  }

  unsigned long long result = (*state) % 256;
  free(state);
  return result;
}

int main() {
  operaciones_bitwise_var9();
  return 0;
}
