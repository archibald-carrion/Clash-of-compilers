// 224.c
// Multiplicación/división en un bucle (variación 3)
#include <stdlib.h>

int calcular_division_float() {
  float* division_f = (float*)malloc(sizeof(float));
  float* divisor = (float*)malloc(sizeof(float));

  if (division_f == NULL || divisor == NULL) {
    free(division_f);
    free(divisor);
    return -1;  // Error en la asignación de memoria
  }

  *division_f = 50000000.0f;
  *divisor = 1.001f;
  for (long long i = 0; i < 1500000; ++i) {
    *division_f /= *divisor;
    if (*division_f < 1.0f)
      *division_f = 50000000.0f;  // Reset to avoid underflow
  }

  int resultado = (int)((long long)*division_f % 256);
  free(division_f);
  free(divisor);
  return resultado;
}

int main() {
  calcular_division_float();
  return 0;
}
