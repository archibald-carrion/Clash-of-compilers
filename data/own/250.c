// 250.c
// Manipulación de array (variación 6)
#define ARRAY_SIZE_250 3072  // Larger array
int main() {
  volatile char array[ARRAY_SIZE_250];
  long long xor_sum = 0;
  for (int k = 0; k < 200; ++k) {
    for (int i = 0; i < ARRAY_SIZE_250; ++i) {
      array[i] = (char)((i * (k + 1)) ^ ((k * k) % 128));
    }
    for (int i = 0; i < ARRAY_SIZE_250; ++i) {
      xor_sum ^= array[i];
    }
  }
  return (int)(xor_sum % 256);
}
