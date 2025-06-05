// 259.c
// Multiplicación/división en un bucle (variación 8)
int main() {
  volatile double res = 1.0;
  for (long long i = 1; i <= 1000000; ++i) {
    if (i % 2 == 0) {
      res *= (1.0 + 0.000001 * (i % 100));
    } else {
      if (res > 1.0) res /= (1.0 + 0.0000005 * (i % 100));
    }
    if (res > 1e10 || res < 1e-5 && res != 0) res = 1.0;
  }
  return (int)((long long)res % 256);
}
