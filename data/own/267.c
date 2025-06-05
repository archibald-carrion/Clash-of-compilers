// 267.c
// Operaciones mixtas (variación 6)
#define MIX_ARR_267 32
int main() {
  volatile unsigned int arr[MIX_ARR_267];
  for (int k = 0; k < MIX_ARR_267; ++k) arr[k] = k * k + 0xBADF00D;
  volatile unsigned long long result_ull = 0;

  for (long long i = 0; i < 600000; ++i) {
    int idx = i % MIX_ARR_267;
    arr[idx] = (arr[idx] << 3) | (arr[idx] >> 29);  // Rotate
    arr[idx] ^= (unsigned int)(i * 1234567UL);
    if ((i % 5) == 0) {
      result_ull += arr[idx];
    } else {
      if (result_ull > arr[idx]) result_ull -= arr[idx];
    }
    if ((i % 101) == 0 && arr[idx] != 0) {  // Infrequent division
      result_ull /= (arr[idx] % 10 + 1);
    }
  }
  return (int)(result_ull % 256);
}
