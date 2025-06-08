// 233.c
// Suma/resta aritmética en un bucle (variación 6)
int main() {
  volatile int resta = 0;
  for (int i = 1000000; i >= 1; --i) {  // Decrementing loop
    resta -= i / ((i % 5) + 1);
  }
  return resta % 256;
}
