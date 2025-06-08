// 216.c
// Operaciones bitwise en un bucle (variación 0)
int main() {
  volatile unsigned int val = 0xABCDEFFF;
  for (long long i = 0; i < 2000000; ++i) {
    val ^= (i & 0xFF);
    val = (val << 3) | (val >> (32 - 3));  // Rotate left
  }
  return (int)(val % 256);
}
