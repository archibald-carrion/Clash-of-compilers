// 214.c
// Multiplicación/división en un bucle (variación 0)
#include <stdlib.h>

int calcular_producto() {
  long long* producto = (long long*)malloc(sizeof(long long));
  if (producto == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *producto = 1;
  for (long long i = 1; i <= 30;
       ++i) {  // Smaller loop for multiplication to avoid overflow quickly
    *producto *= i;
  }

  int resultado = (int)(*producto % 256);
  free(producto);
  return resultado;
}

int main() {
  calcular_producto();
  return 0;
}
