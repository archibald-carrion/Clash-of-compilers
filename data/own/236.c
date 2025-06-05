// 236.c
// Operaciones bitwise en un bucle (variación 4)
int main() {
  volatile unsigned int val = 0xA5A5A5A5;
  for (long long i = 0; i < 2200000; ++i) {
    val ^= (unsigned int)(i * 31 + 17);
    val = (val << 5) | (val >> (32 - 5));
  }
  return (int)(val % 256);
}
