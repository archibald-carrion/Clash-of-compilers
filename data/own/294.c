// 294.c
// Suma/resta aritmética en un bucle (variación 16)
int main() {
  volatile double d_val = 100.0;
  for (long long i = 1; i <= 1400000; ++i) {
    d_val += (i % 2 == 0 ? (double)i / ((i % 8) + 1.0)
                         : -(double)i / ((i % 7) + 1.0));
    if (d_val > 1e7) d_val = 100.0 + (i % 100);
    if (d_val < -1e7) d_val = 100.0 - (i % 100);
  }
  return (int)((long long)d_val % 256);
}
