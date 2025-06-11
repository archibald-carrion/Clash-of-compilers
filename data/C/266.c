// 266.c
// Lógica condicional en bucle (variación 7)
#include <stdlib.h>

int logica_condicional_var7() {
  float* x = malloc(sizeof(float));
  float* y = malloc(sizeof(float));
  float* z = malloc(sizeof(float));
  int* count = malloc(sizeof(int));

  if (!x || !y || !z || !count) {
    free(x);
    free(y);
    free(z);
    free(count);
    return 0;
  }

  *x = 0.5f;
  *y = 0.5f;
  *z = 0.5f;
  *count = 0;

  for (long long i = 0; i < 1000000; ++i) {
    float next_x =
        (*y) * ((i % 100) / 50.0f - 1.0f) + (*z) * ((i % 80) / 40.0f - 1.0f);
    float next_y =
        (*x) * ((i % 120) / 60.0f - 1.0f) + (*z) * ((i % 60) / 30.0f - 1.0f);
    float next_z =
        (*x) * ((i % 140) / 70.0f - 1.0f) + (*y) * ((i % 40) / 20.0f - 1.0f);
    *x = next_x > 1.0f ? 1.0f : (next_x < -1.0f ? -1.0f : next_x);
    *y = next_y > 1.0f ? 1.0f : (next_y < -1.0f ? -1.0f : next_y);
    *z = next_z > 1.0f ? 1.0f : (next_z < -1.0f ? -1.0f : next_z);
    if ((*x) * (*x) + (*y) * (*y) + (*z) * (*z) < 0.1f)
      (*count)++;
    else
      (*count)--;
  }

  int result = (*count) % 256;
  free(x);
  free(y);
  free(z);
  free(count);
  return result;
}

int main() {
  logica_condicional_var7();
  return 0;
}
