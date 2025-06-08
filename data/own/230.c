// 230.c
// Lógica condicional en bucle (variación 1)
#include <stdlib.h>

int logica_condicional_var1() {
  long long* valor = (long long*)malloc(sizeof(long long));
  if (valor == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *valor = 100;
  for (long long i = 1; i <= 3000000; ++i) {
    if (*valor % 2 == 0) {
      *valor = *valor / 2 + i;
    } else {
      *valor = *valor * 3 + 1 - i;
    }
    if (*valor < 0) *valor = -*valor;                        // Keep it positive
    if (*valor > 2000000000) *valor = *valor % 1000000 + 1;  // Prevent overflow
  }

  int resultado = (int)(*valor % 256);
  free(valor);
  return resultado;
}

int main() {
  logica_condicional_var1();
  return 0;
}
