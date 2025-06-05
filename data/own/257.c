// 257.c
// Suma/resta aritmética en un bucle (variación 9)
int main() {
  volatile int suma_a = 0, suma_b = 0;
  for (long long i = 1; i <= 1000000; ++i) {
    suma_a += i;
    suma_b -= i;
    if (i % 10000 == 0) {  // Interleave dependency
      suma_a += suma_b / 1000;
      suma_b += suma_a / 1000;
    }
  }
  return (int)((suma_a ^ suma_b) % 256);
}
