// 282.c
// Suma/resta aritmética en un bucle (variación 14)
#include <stdlib.h>

int suma_resta_var14() {
  float* f_sum = (float*)malloc(sizeof(float));
  if (f_sum == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *f_sum = 0.0f;
  for (long long i = 1; i <= 1600000; ++i) {
    *f_sum += (float)(i % 1000) / ((i % 100) + 1.0f) - 10.0f;
    if (*f_sum > 100000.0f) *f_sum -= 200000.0f;
    if (*f_sum < -100000.0f) *f_sum += 200000.0f;
  }

  int resultado = (int)((long long)*f_sum % 256);
  free(f_sum);
  return resultado;
}

int main() {
  suma_resta_var14();
  return 0;
}
