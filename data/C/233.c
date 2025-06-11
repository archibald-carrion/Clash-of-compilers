// 233.c
// Suma/resta aritmética en un bucle (variación 6)
#include <stdlib.h>

int calcular_resta_var6() {
  int* resta = (int*)malloc(sizeof(int));
  if (resta == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *resta = 0;
  for (int i = 1000000; i >= 1; --i) {  // Decrementing loop
    *resta -= i / ((i % 5) + 1);
  }

  int resultado = *resta % 256;
  free(resta);
  return resultado;
}

int main() {
  calcular_resta_var6();
  return 0;
}
