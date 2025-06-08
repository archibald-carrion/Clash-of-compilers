// 292.c
// Operaciones mixtas (variación 11)
// Simulate a simple digital filter (e.g., moving average)
#define FILTER_TAPS 8
int main() {
  volatile float buffer[FILTER_TAPS];
  for (int i = 0; i < FILTER_TAPS; ++i) buffer[i] = 0.0f;
  int current_idx = 0;
  volatile float output_signal = 0.0f;
  long long final_acc = 0;

  for (long long i = 0; i < 1200000; ++i) {
    float input_signal =
        (float)((i % 2000) - 1000) / 100.0f;  // Generate a sample input
    buffer[current_idx] = input_signal;
    current_idx = (current_idx + 1) % FILTER_TAPS;

    output_signal = 0.0f;
    for (int t = 0; t < FILTER_TAPS; ++t) {
      output_signal += buffer[t];
    }
    output_signal /= FILTER_TAPS;

    if (output_signal > 10.0f)
      final_acc++;
    else if (output_signal < -10.0f)
      final_acc--;
  }
  return (int)(final_acc % 256);
}
