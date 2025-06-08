// 222.c
// Suma/resta aritmética en un bucle (variación 4)
int main() {
  volatile float resta_f = 2500000.0f;
  for (long long i = 1; i <= 600000; ++i) {
    resta_f -= (float)i * 0.75f;
  }
  return (int)((long long)resta_f % 256);
}
