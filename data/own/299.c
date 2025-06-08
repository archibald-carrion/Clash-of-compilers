// 299.c
// Manipulación de array (variación 15) - Final type 4
#include <stdlib.h>
#define ARRAY_SIZE_299 768

long long manipulacion_array_var15() {
  int* data = malloc(ARRAY_SIZE_299 * sizeof(int));
  if (!data) return 0;

  long long* sum_of_medians = malloc(sizeof(long long));
  if (!sum_of_medians) {
    free(data);
    return 0;
  }
  *sum_of_medians = 0;

  for (int iter = 0; iter < 200; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_299; ++i)
      data[i] = (int)((iter * 5 + i * 3 + (iter * i) % 101) % 10000 - 5000);
    // Simple sort for 3 elements to find median-of-3, then sum
    for (int i = 0; i < ARRAY_SIZE_299 - 2; i += 3) {
      int a = data[i], b = data[i + 1], c = data[i + 2];
      int med = (a > b) ? ((b > c) ? b : (a > c ? c : a))
                        : ((a > c) ? a : (b > c ? c : b));
      *sum_of_medians += med;
    }
  }

  long long result = (*sum_of_medians) % 256;
  free(data);
  free(sum_of_medians);
  return result;
}

int main() {
  manipulacion_array_var15();
  return 0;
}
