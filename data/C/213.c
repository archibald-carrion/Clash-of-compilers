// 213.c
// Suma/resta aritmética en un bucle (variación 2)
#include <stdlib.h>

int calcular_suma_alternante() {
  int* suma = (int*)malloc(sizeof(int));
  if (suma == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *suma = 50;  // Data type and initial value variation
  for (int i = 1; i <= 2000000; ++i) {
    if (i % 2 == 0)
      *suma += i;
    else
      *suma -= i;
  }

  int resultado = *suma % 256;
  free(suma);
  return resultado;
}

int main() {
  calcular_suma_alternante();
  return 0;
}
