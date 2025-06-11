// 258.c
// Suma/resta aritmética en un bucle (variación 10)
#include <stdlib.h>

int suma_resta_var10() {
  float* val = (float*)malloc(sizeof(float));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 1000.0f;
  for (long long i = 1; i <= 2500000; ++i) {
    if (i % 3 == 0)
      *val += (float)i / 100.0f;
    else if (i % 3 == 1)
      *val -= (float)i / 150.0f;
    // else do nothing for i%3 == 2, varying workload
    if (*val > 1e6f) *val = 1000.0f;
    if (*val < -1e6f) *val = -1000.0f;
  }

  int resultado = (int)((long long)*val % 256);
  free(val);
  return resultado;
}

int main() {
  suma_resta_var10();
  return 0;
}
