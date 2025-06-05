// 247.c
// Multiplicación/división en un bucle (variación 7)
int main() {
  volatile float dividendo_f = 1.0f;
  for (long long i = 1; i <= 1300000; ++i) {
    dividendo_f *= (1.00001f + (float)(i % 1000) / 1000000.0f);
    if (dividendo_f > 1e10f) dividendo_f = 1.0f;
  }
  return (int)((long long)dividendo_f % 256);
}
