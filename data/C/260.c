// 260.c
// Multiplicación/división en un bucle (variación 9)
#include <stdlib.h>

int multiplicacion_division_var9() {
  unsigned long long* num =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  unsigned int* div = (unsigned int*)malloc(sizeof(unsigned int));
  if (num == NULL || div == NULL) {
    free(num);
    free(div);
    return -1;  // Error en la asignación de memoria
  }

  *num = 1234567890123456789ULL;
  *div = 2;
  for (long long i = 0; i < 1000000; ++i) {
    *num = (*num / *div) + (i % 10000) * 1000ULL;
    *div = (unsigned int)(i % 7) + 2;  // Vary divisor
    if (*num < 1000000ULL) *num = 1234567890123456789ULL - i;
  }

  int resultado = (int)(*num % 256);
  free(num);
  free(div);
  return resultado;
}

int main() {
  multiplicacion_division_var9();
  return 0;
}
