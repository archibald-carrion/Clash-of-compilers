// 240.c
// Lógica condicional en bucle (variación 2)
int main() {
  volatile int resultado = 0;
  for (long long i = 0; i < 6000000; ++i) {
    int temp = i % 100;
    if (temp < 20) {
      resultado += 5;
    } else if (temp < 50) {
      resultado -= 2;
    } else {
      resultado *= 1;  // No change, but an operation
    }
    resultado %= 1000;  // Keep it bounded
  }
  return resultado % 256;
}
