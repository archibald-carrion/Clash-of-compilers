// 246.c
// Multiplicación/división en un bucle (variación 6)
#include <stdlib.h>

int multiplicacion_division_var6() {
  long long* producto = (long long*)malloc(sizeof(long long));
  if (producto == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *producto = 2;
  for (long long i = 1; i <= 32; ++i) {
    *producto *= (i + *producto % 5);  // Dependency on previous product value
    if (*producto > 100000000000000000LL)
      *producto = i;  // Prevent extreme overflow
  }

  int resultado = (int)(*producto % 256);
  free(producto);
  return resultado;
}

int main() {
  multiplicacion_division_var6();
  return 0;
}
