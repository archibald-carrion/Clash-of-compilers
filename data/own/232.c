// 232.c
// Suma/resta aritmética en un bucle (variación 5)
int main() {
  volatile long long suma = -500000;
  for (long long i = 1; i <= 1500000; ++i) {
    suma += (i % 2 == 0) ? i : -i;
  }
  return (int)(suma % 256);
}
