// 294.c
// Suma/resta aritmética en un bucle (variación 16)
#include <stdlib.h>

int suma_resta_var16() {
  double* d_val = (double*)malloc(sizeof(double));
  if (d_val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *d_val = 100.0;
  for (long long i = 1; i <= 1400000; ++i) {
    *d_val += (i % 2 == 0 ? (double)i / ((i % 8) + 1.0)
                          : -(double)i / ((i % 7) + 1.0));
    if (*d_val > 1e7) *d_val = 100.0 + (i % 100);
    if (*d_val < -1e7) *d_val = 100.0 - (i % 100);
  }

  int resultado = (int)((long long)*d_val % 256);
  free(d_val);
  return resultado;
}

int main() {
  suma_resta_var16();
  return 0;
}
