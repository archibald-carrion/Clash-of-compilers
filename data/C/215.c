// 215.c
// Multiplicación/división en un bucle (variación 1)
// Note: Division by zero is undefined. Ensure divisor is never zero.
// Using a fixed divisor and a large dividend to simulate work.
#include <stdlib.h>

int calcular_division() {
  unsigned long long* dividendo =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  unsigned int* divisor = (unsigned int*)malloc(sizeof(unsigned int));

  if (dividendo == NULL || divisor == NULL) {
    free(dividendo);
    free(divisor);
    return -1;  // Error en la asignación de memoria
  }

  *dividendo = 1000000000ULL;
  *divisor = 3;

  for (long long i = 0; i < 1000000; ++i) {
    *dividendo = *dividendo / *divisor +
                 (i % 100);  // Add some minor operation to vary workload
    if (*dividendo == 0)
      *dividendo =
          1000000000ULL;  // Reset if it becomes 0 to continue operations
  }

  int resultado = (int)(*dividendo % 256);
  free(dividendo);
  free(divisor);
  return resultado;
}

int main() {
  calcular_division();
  return 0;
}
