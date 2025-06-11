// 284.c
// Multiplicación/división en un bucle (variación 13)
#include <stdlib.h>

int multiplicacion_division_var13() {
  unsigned long long* num =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  unsigned int* factor = (unsigned int*)malloc(sizeof(unsigned int));
  if (num == NULL || factor == NULL) {
    free(num);
    free(factor);
    return -1;  // Error en la asignación de memoria
  }

  *num = 1ULL;
  *factor = 2;
  for (long long i = 0; i < 60; ++i) {  // Careful with ULLONG_MAX
    *num *= *factor;
    *factor += (i % 3) + 1;
    if (*num > (0xFFFFFFFFFFFFFFFFULL / 200))
      *num = i + 1;  // Prevent overflow by resetting
  }

  int resultado = (int)(*num % 256);
  free(num);
  free(factor);
  return resultado;
}

int main() {
  multiplicacion_division_var13();
  return 0;
}
