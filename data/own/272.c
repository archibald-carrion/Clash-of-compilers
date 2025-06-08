// 272.c
// Multiplicación/división en un bucle (variación 11)
#include <stdlib.h>

int multiplicacion_division_var11() {
  unsigned int* num_a = (unsigned int*)malloc(sizeof(unsigned int));
  unsigned int* num_b = (unsigned int*)malloc(sizeof(unsigned int));
  if (num_a == NULL || num_b == NULL) {
    free(num_a);
    free(num_b);
    return -1;  // Error en la asignación de memoria
  }

  *num_a = 0xFFFFFFFF;
  *num_b = 1;
  for (long long i = 1; i <= 1000000; ++i) {
    if (i % 2 == 0 && *num_b != 0)
      *num_a /= *num_b;
    else
      *num_a *= ((i % 10) + 1);
    *num_b += (i % 5) + 1;
    if (*num_b == 0) *num_b = 1;  // Avoid division by zero
    if (*num_a < 100) *num_a += i;
    if (*num_b > 2000000000) *num_b = 1;
  }

  int resultado = (int)(*num_a % 256);
  free(num_a);
  free(num_b);
  return resultado;
}

int main() {
  multiplicacion_division_var11();
  return 0;
}
