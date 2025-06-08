// 230.c
// Lógica condicional en bucle (variación 1)
int main() {
  volatile long long valor = 100;
  for (long long i = 1; i <= 3000000; ++i) {
    if (valor % 2 == 0) {
      valor = valor / 2 + i;
    } else {
      valor = valor * 3 + 1 - i;
    }
    if (valor < 0) valor = -valor;                        // Keep it positive
    if (valor > 2000000000) valor = valor % 1000000 + 1;  // Prevent overflow
  }
  return (int)(valor % 256);
}
