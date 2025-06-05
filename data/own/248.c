// 248.c
// Operaciones bitwise en un bucle (variación 6)
int main() {
  volatile unsigned int val_a = 0xCAFEBABE, val_b = 0xDEADBEEF;
  for (long long i = 0; i < 1900000; ++i) {
    unsigned int temp = val_a;
    val_a = val_b ^ (unsigned int)(i * i);
    val_b = temp + ((unsigned int)i + 0x9E3779B9);
    val_a = (val_a << 7) | (val_a >> (32 - 7));
  }
  return (int)((val_a ^ val_b) % 256);
}
