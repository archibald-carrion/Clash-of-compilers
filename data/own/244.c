// 244.c
// Suma/resta aritmética en un bucle (variación 7)
int main() {
  volatile long long suma = 100;
  for (long long i = 1; i <= 1800000; ++i) {
    suma += (i * 2) - (i / 2);
  }
  return (int)(suma % 256);
}
