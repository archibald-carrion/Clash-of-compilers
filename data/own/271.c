// 271.c
// Multiplicación/división en un bucle (variación 10)
int main() {
  volatile float prod_f = 0.01f;
  for (long long i = 1; i <= 1100000; ++i) {
    prod_f *=
        (1.0f + ((i % 100) - 49.5f) /
                    10000.0f);  // Multiply by values slightly above or below 1
    if (prod_f > 1e8f || prod_f < 1e-8f && prod_f != 0.0f) {
      prod_f = 0.01f + ((i % 10) / 20.0f);
    }
  }
  return (int)((long long)prod_f % 256);
}
