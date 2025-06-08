// 211.c
// Suma/resta aritmética en un bucle (variación 0)
#include <stdlib.h>

int calcular_suma() {
  long long* suma = (long long*)malloc(sizeof(long long));
  if (suma == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *suma = 0;  // Initial value variation
  for (long long i = 1; i <= 1000000; ++i) {
    *suma += i;
  }

  int resultado = (int)(*suma % 256);
  free(suma);
  return resultado;
}

int main() {
  calcular_suma();
  return 0;  // Return 0 to indicate successful execution
}
