// 249.c
// Operaciones bitwise en un bucle (variación 7)
int main() {
  volatile unsigned long long val = 0x0123456789ABCDEFULL;
  for (long long i = 0; i < 1400000; ++i) {
    val = ~val ^ (val >> 3);
    val = val & (0xFFFFFFFFFFFFFFFFULL / ((i % 10) + 1));
    val = val | (i * 0xBADF00DULL);
  }
  return (int)(val % 256);
}
