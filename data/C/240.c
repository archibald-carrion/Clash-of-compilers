// 240.c
// Lógica condicional en bucle (variación 2)
#include <stdlib.h>

int logica_condicional_var2() {
  int* resultado = (int*)malloc(sizeof(int));
  if (resultado == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *resultado = 0;
  for (long long i = 0; i < 6000000; ++i) {
    int temp = i % 100;
    if (temp < 20) {
      *resultado += 5;
    } else if (temp < 50) {
      *resultado -= 2;
    } else {
      *resultado *= 1;  // No change, but an operation
    }
    *resultado %= 1000;  // Keep it bounded
  }

  int result_val = *resultado % 256;
  free(resultado);
  return result_val;
}

int main() {
  logica_condicional_var2();
  return 0;
}
