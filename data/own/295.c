// 295.c
// Multiplicación/división en un bucle (variación 14) - Final type 2
#include <stdlib.h>

int multiplicacion_division_var14() {
  float* f_prod = (float*)malloc(sizeof(float));
  if (f_prod == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *f_prod = 1.0f;
  for (long long i = 1; i <= 1050000; ++i) {
    *f_prod *= (1.00000f + ((i % 100) - 50.0f) / 200000.0f);
    if (*f_prod > 1000.0f || *f_prod < 0.001f && *f_prod != 0)
      *f_prod = 1.0f + (i % 10) / 100.0f;
  }

  int resultado = (int)((long long)(*f_prod * 10.0f) % 256);
  free(f_prod);
  return resultado;
}

int main() {
  multiplicacion_division_var14();
  return 0;
}
