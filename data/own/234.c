// 234.c
// Multiplicación/división en un bucle (variación 4)
int main() {
  volatile unsigned long long producto = 1;
  for (long long i = 1; i <= 35; ++i) {
    producto *= (i + 1);  // Slightly different operation
  }
  return (int)(producto % 256);
}
