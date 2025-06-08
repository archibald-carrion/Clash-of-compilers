// 215.c
// Multiplicación/división en un bucle (variación 1)
// Note: Division by zero is undefined. Ensure divisor is never zero.
// Using a fixed divisor and a large dividend to simulate work.
int main() {
  volatile unsigned long long dividendo = 1000000000ULL;
  unsigned int divisor = 3;
  for (long long i = 0; i < 1000000; ++i) {
    dividendo = dividendo / divisor +
                (i % 100);  // Add some minor operation to vary workload
    if (dividendo == 0)
      dividendo =
          1000000000ULL;  // Reset if it becomes 0 to continue operations
  }
  return (int)(dividendo % 256);
}
