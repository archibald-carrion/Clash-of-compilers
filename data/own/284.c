// 284.c
// Multiplicación/división en un bucle (variación 13)
int main() {
  volatile unsigned long long num = 1ULL;
  unsigned int factor = 2;
  for (long long i = 0; i < 60; ++i) {  // Careful with ULLONG_MAX
    num *= factor;
    factor += (i % 3) + 1;
    if (num > (0xFFFFFFFFFFFFFFFFULL / 200))
      num = i + 1;  // Prevent overflow by resetting
  }
  return (int)(num % 256);
}
