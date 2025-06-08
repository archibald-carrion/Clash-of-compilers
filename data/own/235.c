// 235.c
// Multiplicación/división en un bucle (variación 5)
int main() {
  volatile double dividendo = 200000000.0;
  double divisor = 1.00000001;
  for (long long i = 0; i < 1200000; ++i) {
    dividendo = dividendo / divisor;
    if (dividendo < 1.0) dividendo = 200000000.0;
  }
  return (int)((long long)dividendo % 256);
}
