// 276.c
// Manipulación de array (variación 12)
#include <stdlib.h>

#define ARRAY_SIZE_276 128

int manipulacion_array_var12() {
  float* circular_buffer = (float*)malloc(ARRAY_SIZE_276 * sizeof(float));
  if (circular_buffer == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  int* head = (int*)malloc(sizeof(int));
  float* current_sum = (float*)malloc(sizeof(float));
  if (head == NULL || current_sum == NULL) {
    free(circular_buffer);
    free(head);
    free(current_sum);
    return -1;  // Error en la asignación de memoria
  }

  *head = 0;
  *current_sum = 0.0f;
  for (int i = 0; i < ARRAY_SIZE_276; ++i) circular_buffer[i] = 0.0f;

  for (long long iter = 0; iter < 200000; ++iter) {
    float new_val = (float)(iter % 1000) / 100.0f - 5.0f;
    *current_sum -= circular_buffer[*head];
    circular_buffer[*head] = new_val;
    *current_sum += new_val;
    *head = (*head + 1) % ARRAY_SIZE_276;
  }

  int resultado = (int)((long long)*current_sum % 256);
  free(circular_buffer);
  free(head);
  free(current_sum);
  return resultado;
}

int main() {
  manipulacion_array_var12();
  return 0;
}
