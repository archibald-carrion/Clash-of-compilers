// 292.c
// Operaciones mixtas (variación 11)
// Simulate a simple digital filter (e.g., moving average)
#include <stdlib.h>
#define FILTER_TAPS 8

long long operaciones_mixtas_var11() {
  float* buffer = malloc(FILTER_TAPS * sizeof(float));
  if (!buffer) return 0;

  for (int i = 0; i < FILTER_TAPS; ++i) buffer[i] = 0.0f;

  int* current_idx = malloc(sizeof(int));
  float* output_signal = malloc(sizeof(float));
  long long* final_acc = malloc(sizeof(long long));

  if (!current_idx || !output_signal || !final_acc) {
    free(buffer);
    free(current_idx);
    free(output_signal);
    free(final_acc);
    return 0;
  }

  *current_idx = 0;
  *output_signal = 0.0f;
  *final_acc = 0;

  for (long long i = 0; i < 1200000; ++i) {
    float input_signal =
        (float)((i % 2000) - 1000) / 100.0f;  // Generate a sample input
    buffer[*current_idx] = input_signal;
    *current_idx = ((*current_idx) + 1) % FILTER_TAPS;

    *output_signal = 0.0f;
    for (int t = 0; t < FILTER_TAPS; ++t) {
      *output_signal += buffer[t];
    }
    *output_signal /= FILTER_TAPS;

    if (*output_signal > 10.0f)
      (*final_acc)++;
    else if (*output_signal < -10.0f)
      (*final_acc)--;
  }

  long long result = (*final_acc) % 256;
  free(buffer);
  free(current_idx);
  free(output_signal);
  free(final_acc);
  return result;
}

int main() {
  operaciones_mixtas_var11();
  return 0;
}
