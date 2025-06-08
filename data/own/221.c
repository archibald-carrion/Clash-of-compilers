// 221.c
// Suma/resta aritmética en un bucle (variación 3)
int main() {
  volatile double suma_d = 0.0;
  for (long long i = 1; i <= 1200000; ++i) {
    suma_d += (double)i / 2.5;
  }
  return (int)((long long)suma_d % 256);
}
