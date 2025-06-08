// 234.c
// Multiplicación/división en un bucle (variación 4)
#include <stdlib.h>

int calcular_producto_var4() {
  unsigned long long* producto =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  if (producto == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *producto = 1;
  for (long long i = 1; i <= 35; ++i) {
    *producto *= (i + 1);  // Slightly different operation
  }

  int resultado = (int)(*producto % 256);
  free(producto);
  return resultado;
}

int main() {
  calcular_producto_var4();
  return 0;
}
