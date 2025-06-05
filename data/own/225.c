// 225.c
// Operaciones bitwise en un bucle (variación 2)
int main() {
  volatile unsigned int val = 0x12345678;
  for (long long i = 0; i < 2500000; ++i) {
    val = (val >> 1) ^ ((i % 255) << 24);
  }
  return (int)(val % 256);
}
