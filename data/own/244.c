// 244.c
// Suma/resta aritmética en un bucle (variación 7)
#include <stdlib.h>

int suma_resta_var7() {
  long long* suma = (long long*)malloc(sizeof(long long));
  if (suma == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *suma = 100;
  for (long long i = 1; i <= 1800000; ++i) {
    *suma += (i * 2) - (i / 2);
  }

  int resultado = (int)(*suma % 256);
  free(suma);
  return resultado;
}

int main() {
  suma_resta_var7();
  return 0;
}
