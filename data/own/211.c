// 211.c
// Suma/resta aritmética en un bucle (variación 0)
int main() {
  volatile long long suma = 0;  // Initial value variation
  for (long long i = 1; i <= 1000000; ++i) {
    suma += i;
  }
  return (int)(suma % 256);
}
