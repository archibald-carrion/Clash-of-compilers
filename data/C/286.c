// 286.c
// Operaciones bitwise en un bucle (variación 13)
// Count set bits (Hamming weight) in a loop
#include <stdlib.h>

int operaciones_bitwise_var13() {
  unsigned long long* n =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  int* total_set_bits = (int*)malloc(sizeof(int));
  if (n == NULL || total_set_bits == NULL) {
    free(n);
    free(total_set_bits);
    return -1;  // Error en la asignación de memoria
  }

  *n = 0xAAAAAAAAAAAAAAAAULL;
  *total_set_bits = 0;
  for (long long i = 0; i < 1000000; ++i) {
    unsigned long long temp_n = *n + i;  // Vary the number being checked
    int set_bits = 0;
    while (temp_n > 0) {
      temp_n &= (temp_n - 1);  // Brian Kernighan's algorithm
      set_bits++;
    }
    *total_set_bits += set_bits;
  }

  int resultado = *total_set_bits % 256;
  free(n);
  free(total_set_bits);
  return resultado;
}

int main() {
  operaciones_bitwise_var13();
  return 0;
}
