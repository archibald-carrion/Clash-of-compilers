// 222.c
// Suma/resta aritmética en un bucle (variación 4)
#include <stdlib.h>

int calcular_resta_float() {
  float* resta_f = (float*)malloc(sizeof(float));
  if (resta_f == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *resta_f = 2500000.0f;
  for (long long i = 1; i <= 600000; ++i) {
    *resta_f -= (float)i * 0.75f;
  }

  int resultado = (int)((long long)*resta_f % 256);
  free(resta_f);
  return resultado;
}

int main() {
  calcular_resta_float();
  return 0;
}
