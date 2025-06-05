// 256.c
// Operaciones mixtas (variación 5)
int main() {
  volatile double val_d = 100.0;
  volatile unsigned long long val_ull = 100ULL;
  for (long long i = 1; i <= 750000; ++i) {
    val_d +=
        (i % 2 == 0) ? (val_d / ((i % 10) + 1.0)) : -(val_d * 0.001 * (i % 5));
    val_ull ^= (i << (i % 5));
    val_ull += (unsigned long long)(val_d + i);
    if (val_d > 1e8)
      val_d = 100.0;
    else if (val_d < 1e-4 && val_d != 0)
      val_d = 1.0;
  }
  return (int)(val_ull % 256);
}
