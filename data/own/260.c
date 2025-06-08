// 260.c
// Multiplicación/división en un bucle (variación 9)
int main() {
  volatile unsigned long long num = 1234567890123456789ULL;
  unsigned int div = 2;
  for (long long i = 0; i < 1000000; ++i) {
    num = (num / div) + (i % 10000) * 1000ULL;
    div = (unsigned int)(i % 7) + 2;  // Vary divisor
    if (num < 1000000ULL) num = 1234567890123456789ULL - i;
  }
  return (int)(num % 256);
}
