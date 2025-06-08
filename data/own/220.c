// 220.c
// Operaciones mixtas (variación 0)
int main() {
  volatile long long acc = 12345;
  for (long long i = 1; i <= 800000; ++i) {
    acc += (i % 1000);
    acc ^= (i << 2);
    if (i % 100 == 0 && acc != 0) {
      acc = (acc / ((i % 10) + 1)) + (i & 0xFF);
    }
  }
  return (int)(acc % 256);
}
