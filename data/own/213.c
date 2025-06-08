// 213.c
// Suma/resta aritmética en un bucle (variación 2)
int main() {
  volatile int suma = 50;  // Data type and initial value variation
  for (int i = 1; i <= 2000000; ++i) {
    if (i % 2 == 0)
      suma += i;
    else
      suma -= i;
  }
  return suma % 256;
}
