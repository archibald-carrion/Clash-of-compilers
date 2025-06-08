// 245.c
// Suma/resta aritmética en un bucle (variación 8)
int main() {
  volatile double resta_d = 500000.0;
  for (long long i = 1; i <= 700000; ++i) {
    resta_d -= (double)i / ((i % 10) + 1.1);
  }
  return (int)((long long)resta_d % 256);
}
