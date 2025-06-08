// 277.c
// Lógica condicional en bucle (variación 8)
#include <stdlib.h>

int logica_condicional_var8() {
  int* x = (int*)malloc(sizeof(int));
  int* y = (int*)malloc(sizeof(int));
  int* z = (int*)malloc(sizeof(int));
  long long* accumulator = (long long*)malloc(sizeof(long long));
  if (x == NULL || y == NULL || z == NULL || accumulator == NULL) {
    free(x);
    free(y);
    free(z);
    free(accumulator);
    return -1;  // Error en la asignación de memoria
  }

  *x = 0;
  *y = 0;
  *z = 0;
  *accumulator = 0;
  for (long long i = 0; i < 3200000; ++i) {
    *x = (int)(i % 100) - 50;
    *y = (int)((i / 100) % 100) - 50;
    *z = (int)((i / 10000) % 100) - 50;
    if (*x > 0 && *y > 0 && *z > 0)
      *accumulator += (*x + *y + *z);
    else if (*x < 0 && *y < 0 && *z < 0)
      *accumulator += (*x * *y * *z);
    else
      *accumulator -= (*x - *y - *z);
    if (*accumulator > 100000000) *accumulator = *accumulator % 100000000;
    if (*accumulator < -100000000) *accumulator = *accumulator % 100000000;
  }

  int resultado = (int)(*accumulator % 256);
  free(x);
  free(y);
  free(z);
  free(accumulator);
  return resultado;
}

int main() {
  logica_condicional_var8();
  return 0;
}
