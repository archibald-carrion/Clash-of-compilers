// 285.c
// Operaciones bitwise en un bucle (variación 12)
int main() {
  volatile unsigned int val1 = 0x1A2B3C4D, val2 = 0x5E6F7A8B;
  for (long long i = 0; i < 2100000; ++i) {
    val1 ^= (val2 >> (i % 8)) + (unsigned int)i;
    val2 ^= (val1 << (i % 4)) + (unsigned int)(i * 3);
    if (i % 100 == 0) {
      val1 = ~val1;
      val2 = ~val2;
    }
  }
  return (int)((val1 ^ val2) % 256);
}
