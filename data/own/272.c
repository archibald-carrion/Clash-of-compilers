// 272.c
// Multiplicación/división en un bucle (variación 11)
int main() {
  volatile unsigned int num_a = 0xFFFFFFFF, num_b = 1;
  for (long long i = 1; i <= 1000000; ++i) {
    if (i % 2 == 0 && num_b != 0)
      num_a /= num_b;
    else
      num_a *= ((i % 10) + 1);
    num_b += (i % 5) + 1;
    if (num_b == 0) num_b = 1;  // Avoid division by zero
    if (num_a < 100) num_a += i;
    if (num_b > 2000000000) num_b = 1;
  }
  return (int)(num_a % 256);
}
