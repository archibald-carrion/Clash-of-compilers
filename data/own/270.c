// 270.c
// Suma/resta aritmética en un bucle (variación 12)
int main() {
  volatile double val_a = 0.0, val_b = 10000.0;
  for (long long i = 1; i <= 900000; ++i) {
    val_a += (double)i / ((i % 20) + 0.5);
    val_b -= (double)i / ((i % 25) + 0.8);
    if (i % 5000 == 0) {
      double temp = val_a;
      val_a = val_b;
      val_b = temp;
    }
  }
  return (int)(((long long)val_a + (long long)val_b) % 256);
}
