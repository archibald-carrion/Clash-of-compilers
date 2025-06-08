// 297.c
// Operaciones bitwise en un bucle (variación 14) - Final type 3
int main() {
  volatile unsigned long long pattern = 0xF0F0F0F0F0F0F0F0ULL;
  for (long long i = 0; i < 1800000; ++i) {
    pattern ^= (i << (i % 16));
    pattern = (pattern >> (i % 3)) | (pattern << (64 - (i % 3)));
  }
  return (int)(pattern % 256);
}
