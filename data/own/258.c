// 258.c
// Suma/resta aritmética en un bucle (variación 10)
int main() {
  volatile float val = 1000.0f;
  for (long long i = 1; i <= 2500000; ++i) {
    if (i % 3 == 0)
      val += (float)i / 100.0f;
    else if (i % 3 == 1)
      val -= (float)i / 150.0f;
    // else do nothing for i%3 == 2, varying workload
    if (val > 1e6f) val = 1000.0f;
    if (val < -1e6f) val = -1000.0f;
  }
  return (int)((long long)val % 256);
}
