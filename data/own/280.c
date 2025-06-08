// 280.c
// Operaciones mixtas (variación 9)
// Fibonacci sequence generation with some twists
#include <stdlib.h>

int operaciones_mixtas_var9() {
  unsigned long long* fib_a =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  unsigned long long* fib_b =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  unsigned long long* temp_fib =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  unsigned int* bit_mangler = (unsigned int*)malloc(sizeof(unsigned int));
  long long* sum_check = (long long*)malloc(sizeof(long long));

  if (fib_a == NULL || fib_b == NULL || temp_fib == NULL ||
      bit_mangler == NULL || sum_check == NULL) {
    free(fib_a);
    free(fib_b);
    free(temp_fib);
    free(bit_mangler);
    free(sum_check);
    return -1;  // Error en la asignación de memoria
  }

  *fib_a = 0;
  *fib_b = 1;
  *bit_mangler = 0xDEADBEEF;
  *sum_check = 0;

  for (long long i = 0; i < 90;
       ++i) {  // Fibonacci grows fast, limit iterations
    *temp_fib = *fib_a + *fib_b;
    *fib_a = *fib_b;
    *fib_b = *temp_fib;

    if (i % 3 == 0)
      *bit_mangler ^= (unsigned int)(*fib_b & 0xFFFFFFFF);
    else
      *bit_mangler =
          (*bit_mangler >> 1) + (unsigned int)((*fib_a >> 32) & 0xFFFFFFFF);

    *sum_check += (long long)(*bit_mangler % 1000) - 500;
  }

  int resultado = (int)((*fib_b + *bit_mangler + *sum_check) % 256);
  free(fib_a);
  free(fib_b);
  free(temp_fib);
  free(bit_mangler);
  free(sum_check);
  return resultado;
}

int main() {
  operaciones_mixtas_var9();
  return 0;
}
