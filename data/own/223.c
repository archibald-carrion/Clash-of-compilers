// 223.c
// Multiplicación/división en un bucle (variación 2)
#include <stdlib.h>

int calcular_producto_double() {
  double* producto_d = (double*)malloc(sizeof(double));
  if (producto_d == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *producto_d = 1.0;
  for (int i = 1; i <= 60; ++i) {  // Loop count adjusted for double precision
    *producto_d *= (double)i * 1.000001;
  }

  int resultado = (int)((long long)*producto_d % 256);
  free(producto_d);
  return resultado;
}

int main() {
  calcular_producto_double();
  return 0;
}
