// 232.c
// Suma/resta aritmética en un bucle (variación 5)
#include <stdlib.h>

int calcular_suma_var5() {
  long long* suma = (long long*)malloc(sizeof(long long));
  if (suma == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *suma = -500000;
  for (long long i = 1; i <= 1500000; ++i) {
    *suma += (i % 2 == 0) ? i : -i;
  }

  int resultado = (int)(*suma % 256);
  free(suma);
  return resultado;
}

int main() {
  calcular_suma_var5();
  return 0;
}
