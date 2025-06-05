// 263.c
// Manipulación de array (variación 9)
#define ARRAY_SIZE_263 640
int main() {
  volatile int array[ARRAY_SIZE_263];
  long long sum_sq_diff = 0;
  for (int iter = 0; iter < 300; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_263; ++i) {
      array[i] = (iter + 1) * (i - ARRAY_SIZE_263 / 2);
    }
    for (int i = 0; i < ARRAY_SIZE_263 - 1; ++i) {
      long long diff = array[i + 1] - array[i];
      sum_sq_diff += diff * diff;
    }
  }
  return (int)(sum_sq_diff % 256);
}
