// 283.c
// Multiplicación/división en un bucle (variación 12)
int main() {
  volatile double val = 1.000000001;
  for (long long i = 1; i <= 950000; ++i) {
    val *= (1.0 + (double)((i % 10) - 5) / 100000.0);
    if (val < 0.5 || val > 2.0) val = 1.000000001 + (double)(i % 10) / 10000.0;
  }
  return (int)((long long)(val * 1000.0) % 256);
}
