// 281.c
// Suma/resta aritmética en un bucle (variación 13)
#include <stdlib.h>

int suma_resta_var13() {
  long long* val = (long long*)malloc(sizeof(long long));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 0;
  for (long long i = 1; i <= 2000000; ++i) {
    *val += (i % 100) - ((i / 100) % 50);
  }

  int resultado = (int)(*val % 256);
  free(val);
  return resultado;
}

int main() {
  suma_resta_var13();
  return 0;
}
