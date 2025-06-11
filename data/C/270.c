// 270.c
// Suma/resta aritmética en un bucle (variación 12)
#include <stdlib.h>

int suma_resta_var12() {
  double* val_a = (double*)malloc(sizeof(double));
  double* val_b = (double*)malloc(sizeof(double));
  if (val_a == NULL || val_b == NULL) {
    free(val_a);
    free(val_b);
    return -1;  // Error en la asignación de memoria
  }

  *val_a = 0.0;
  *val_b = 10000.0;
  for (long long i = 1; i <= 900000; ++i) {
    *val_a += (double)i / ((i % 20) + 0.5);
    *val_b -= (double)i / ((i % 25) + 0.8);
    if (i % 5000 == 0) {
      double temp = *val_a;
      *val_a = *val_b;
      *val_b = temp;
    }
  }

  int resultado = (int)(((long long)*val_a + (long long)*val_b) % 256);
  free(val_a);
  free(val_b);
  return resultado;
}

int main() {
  suma_resta_var12();
  return 0;
}
