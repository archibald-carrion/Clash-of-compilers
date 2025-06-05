// 255.c
// Operaciones mixtas (variación 4)
#define MIX_ARRAY_SIZE 128
int main() {
  volatile int arr[MIX_ARRAY_SIZE];
  volatile long long accumulator = 0;
  for (int i = 0; i < MIX_ARRAY_SIZE; ++i) arr[i] = i * 3 - 50;

  for (long long i = 0; i < 500000; ++i) {
    int idx1 = i % MIX_ARRAY_SIZE;
    int idx2 = (i * 7) % MIX_ARRAY_SIZE;
    arr[idx1] += (int)(i % 100) - 50;
    arr[idx2] ^= (int)(i >> 8);
    if (arr[idx1] > arr[idx2]) {
      accumulator += arr[idx1];
    } else {
      accumulator -= arr[idx2];
    }
    if (i % 1000 == 0) {  // Infrequent heavier operation
      for (int k = 0; k < MIX_ARRAY_SIZE / 2; ++k)
        arr[k] = arr[MIX_ARRAY_SIZE - 1 - k];
    }
    if (accumulator > 2000000000LL) accumulator /= 2;
    if (accumulator < -2000000000LL) accumulator /= 2;
  }
  return (int)(accumulator % 256);
}
