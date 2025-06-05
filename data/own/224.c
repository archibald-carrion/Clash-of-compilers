// 224.c
// Multiplicación/división en un bucle (variación 3)
int main() {
  volatile float division_f = 50000000.0f;
  float divisor = 1.001f;
  for (long long i = 0; i < 1500000; ++i) {
    division_f /= divisor;
    if (division_f < 1.0f)
      division_f = 50000000.0f;  // Reset to avoid underflow
  }
  return (int)((long long)division_f % 256);
}
