// 247.c
// Multiplicación/división en un bucle (variación 7)
#include <stdlib.h>

int multiplicacion_division_var7() {
  float* dividendo_f = (float*)malloc(sizeof(float));
  if (dividendo_f == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *dividendo_f = 1.0f;
  for (long long i = 1; i <= 1300000; ++i) {
    *dividendo_f *= (1.00001f + (float)(i % 1000) / 1000000.0f);
    if (*dividendo_f > 1e10f) *dividendo_f = 1.0f;
  }

  int resultado = (int)((long long)*dividendo_f % 256);
  free(dividendo_f);
  return resultado;
}

int main() {
  multiplicacion_division_var7();
  return 0;
}
