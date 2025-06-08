// 288.c
// Manipulación de array (variación 14)
#include <stdlib.h>
#define ARRAY_SIZE_288 96

long long manipulacion_array_var14() {
  double* array_x = malloc(ARRAY_SIZE_288 * sizeof(double));
  if (!array_x) return 0;

  double* array_y = malloc(ARRAY_SIZE_288 * sizeof(double));
  if (!array_y) {
    free(array_x);
    return 0;
  }

  double* distance_sum = malloc(sizeof(double));
  if (!distance_sum) {
    free(array_x);
    free(array_y);
    return 0;
  }
  *distance_sum = 0.0;

  for (int iter = 0; iter < 10000;
       ++iter) {  // More iterations for smaller array
    for (int i = 0; i < ARRAY_SIZE_288; ++i) {
      array_x[i] = (double)((iter + i * 2) % 1000) / 100.0;
      array_y[i] = (double)((iter + i * 3) % 1000) / 100.0;
    }
    for (int i = 0; i < ARRAY_SIZE_288; ++i) {
      double dx = array_x[i] - array_x[(i + 1) % ARRAY_SIZE_288];
      double dy = array_y[i] - array_y[(i + 1) % ARRAY_SIZE_288];
      // distance_sum += sqrt(dx*dx + dy*dy); // sqrt is from math.h, avoid
      *distance_sum += dx * dx + dy * dy;  // Use squared distance to avoid sqrt
    }
    if (*distance_sum > 1e7) *distance_sum /= 1e3;
  }

  long long result = (long long)*distance_sum % 256;
  free(array_x);
  free(array_y);
  free(distance_sum);
  return result;
}

int main() {
  manipulacion_array_var14();
  return 0;
}
