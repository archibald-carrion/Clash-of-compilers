// 296.c
// Multiplicación/división en un bucle (variación 15)
#include <stdlib.h>

int multiplicacion_division_var15() {
  unsigned int* num = (unsigned int*)malloc(sizeof(unsigned int));
  unsigned int* den = (unsigned int*)malloc(sizeof(unsigned int));
  unsigned int* res = (unsigned int*)malloc(sizeof(unsigned int));
  if (num == NULL || den == NULL || res == NULL) {
    free(num);
    free(den);
    free(res);
    return -1;  // Error en la asignación de memoria
  }

  *num = 1;
  *den = 1;
  *res = 0;
  for (long long i = 1; i <= 1300000; ++i) {
    *num *= ((i % 5) + 1);
    *den *= ((i % 3) + 1);
    if (*den == 0) *den = 1;
    *res += *num / *den;
    if (*num > 2000000000) *num = (i % 100) + 1;
    if (*den > 2000000000) *den = (i % 50) + 1;
  }

  int resultado = (int)(*res % 256);
  free(num);
  free(den);
  free(res);
  return resultado;
}

int main() {
  multiplicacion_division_var15();
  return 0;
}
