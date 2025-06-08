// 296.c
// Multiplicación/división en un bucle (variación 15)
int main() {
  volatile unsigned int num = 1, den = 1;
  unsigned int res = 0;
  for (long long i = 1; i <= 1300000; ++i) {
    num *= ((i % 5) + 1);
    den *= ((i % 3) + 1);
    if (den == 0) den = 1;
    res += num / den;
    if (num > 2000000000) num = (i % 100) + 1;
    if (den > 2000000000) den = (i % 50) + 1;
  }
  return (int)(res % 256);
}
