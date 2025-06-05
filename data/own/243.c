// 243.c
// Operaciones mixtas (variación 3)
#define ARRAY_SIZE_243 64
int main() {
  volatile float arr[ARRAY_SIZE_243];
  float sum_f = 0.0f;
  for (int i = 0; i < ARRAY_SIZE_243; ++i) arr[i] = (float)i / 2.0f;

  for (long long iter = 0; iter < 80000; ++iter) {
    int idx = iter % ARRAY_SIZE_243;
    arr[idx] += (float)(iter % 13) * 0.8f;
    arr[idx] -= (float)((iter + 30) % 23) * 0.5f;
    if (arr[idx] < 0.0f) arr[idx] = 0.0f;
    if (iter % 5 == 0) sum_f += arr[idx];
    if (sum_f > 1e6f) sum_f = 0.0f;
  }
  return (int)((long long)sum_f % 256);
}
