// 229.c
// Lógica condicional en bucle (variación 0)
#include <stdlib.h>

int logica_condicional() {
  int* contador = (int*)malloc(sizeof(int));
  if (contador == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *contador = 0;
  for (long long i = 0; i < 5000000; ++i) {
    if ((i % 3 == 0) && (i % 5 != 0)) {
      (*contador)++;
    } else if (i % 7 == 0) {
      (*contador)--;
    }
  }

  int resultado = *contador % 256;
  free(contador);
  return resultado;
}

int main() {
  logica_condicional();
  return 0;
}
