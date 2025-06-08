// 237.c
// Operaciones bitwise en un bucle (variación 5)
int main() {
  volatile unsigned long long val = 0x1122334455667788ULL;
  for (long long i = 0; i < 1600000; ++i) {
    val = val ^ (val >> 7);
    val = val ^ (val << 13);
    val = val ^ (val >> 21);
  }
  return (int)(val % 256);
}
