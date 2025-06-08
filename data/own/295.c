// 295.c
// Multiplicación/división en un bucle (variación 14) - Final type 2
int main() {
  volatile float f_prod = 1.0f;
  for (long long i = 1; i <= 1050000; ++i) {
    f_prod *= (1.00000f + ((i % 100) - 50.0f) / 200000.0f);
    if (f_prod > 1000.0f || f_prod < 0.001f && f_prod != 0)
      f_prod = 1.0f + (i % 10) / 100.0f;
  }
  return (int)((long long)(f_prod * 10.0f) % 256);
}
