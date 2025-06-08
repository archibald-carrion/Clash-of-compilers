// 212.c
// Suma/resta aritmética en un bucle (variación 1)
int main() {
  volatile long long resta = 1000000;  // Initial value variation
  for (long long i = 1; i <= 500000; ++i) {
    resta -= i;
  }
  return (int)(resta % 256);
}
