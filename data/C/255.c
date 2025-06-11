// 255.c
// Operaciones mixtas (variación 4)
#include <stdio.h>
#include <stdlib.h>

#define MIX_ARRAY_SIZE 128

// Función auxiliar con la lógica principal
int run_logic_255() {
  int *arr;
  long long accumulator = 0;

  // Asignación dinámica
  arr = (int *)malloc(MIX_ARRAY_SIZE * sizeof(int));
  if (arr == NULL) {
    // Manejo de error de asignación de memoria
    return -1;  // O algún código de error apropiado
  }

  for (int i = 0; i < MIX_ARRAY_SIZE; ++i) arr[i] = i * 3 - 50;

  for (long long i = 0; i < 500000; ++i) {
    accumulator += arr[i % MIX_ARRAY_SIZE] * (i % 5 - 2);
    if (i % 10000 == 0 && i > 0) {
      arr[i % MIX_ARRAY_SIZE] = (int)(accumulator % 1000) - 500;
    }
  }

  // Liberar memoria
  free(arr);

  return (int)(accumulator % 256);
}

int main() {
  run_logic_255();
  return 0;
}
