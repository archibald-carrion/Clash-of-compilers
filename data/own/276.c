// 276.c
// Manipulación de array (variación 12)
#define ARRAY_SIZE_276 128
int main() {
  volatile float circular_buffer[ARRAY_SIZE_276];
  int head = 0;
  float current_sum = 0.0f;
  for (int i = 0; i < ARRAY_SIZE_276; ++i) circular_buffer[i] = 0.0f;

  for (long long iter = 0; iter < 200000; ++iter) {
    float new_val = (float)(iter % 1000) / 100.0f - 5.0f;
    current_sum -= circular_buffer[head];
    circular_buffer[head] = new_val;
    current_sum += new_val;
    head = (head + 1) % ARRAY_SIZE_276;
  }
  return (int)((long long)current_sum % 256);
}
