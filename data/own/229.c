// 229.c
// Lógica condicional en bucle (variación 0)
int main() {
  volatile int contador = 0;
  for (long long i = 0; i < 5000000; ++i) {
    if ((i % 3 == 0) && (i % 5 != 0)) {
      contador++;
    } else if (i % 7 == 0) {
      contador--;
    }
  }
  return contador % 256;
}
