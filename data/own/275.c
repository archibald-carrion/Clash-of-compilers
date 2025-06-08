// 275.c
// Manipulación de array (variación 11)
#define ARRAY_SIZE_275 896  // (1024 - 128)
int main() {
  volatile short array_a[ARRAY_SIZE_275];
  volatile short array_b[ARRAY_SIZE_275];
  long long dot_product = 0;
  for (int iter = 0; iter < 150; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_275; ++i) {
      array_a[i] = (short)((i * (iter + 1)) % 1000 - 500);
      array_b[i] =
          (short)(((ARRAY_SIZE_275 - 1 - i) * (iter + 1)) % 1000 - 500);
    }
    dot_product = 0;  // Reset for each iteration's calculation
    for (int i = 0; i < ARRAY_SIZE_275; ++i) {
      dot_product += (long long)array_a[i] * array_b[i];
    }
  }
  return (int)(dot_product % 256);
}
