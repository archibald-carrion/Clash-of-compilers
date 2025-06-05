// 287.c
// Manipulación de array (variación 13)
#define ARRAY_SIZE_287 1152  // (1024 + 128)
int main() {
  volatile int array[ARRAY_SIZE_287];
  long long sum_abs_diff = 0;
  for (int iter = 0; iter < 120; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_287; ++i) {
      array[i] = (int)(((iter + i) * (iter + i) * 13) % 2000 - 1000);
    }
    for (int i = 0; i < ARRAY_SIZE_287 - 1; i += 2) {
      long long diff = array[i + 1] - array[i];
      sum_abs_diff += (diff > 0 ? diff : -diff);  // abs(diff)
    }
  }
  return (int)(sum_abs_diff % 256);
}
