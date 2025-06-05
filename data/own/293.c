// 293.c
// Suma/resta aritmética en un bucle (variación 15) - Final type 1
int main() {
  volatile int acc = 0;
  for (long long i = 1; i <= 2200000; ++i) {
    acc += (int)(i % 10) - (int)((i / 10) % 10);
  }
  return acc % 256;
}
