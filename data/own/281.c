// 281.c
// Suma/resta aritmética en un bucle (variación 13)
int main() {
  volatile long long val = 0;
  for (long long i = 1; i <= 2000000; ++i) {
    val += (i % 100) - ((i / 100) % 50);
  }
  return (int)(val % 256);
}
