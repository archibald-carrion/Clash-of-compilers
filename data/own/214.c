// 214.c
// Multiplicación/división en un bucle (variación 0)
int main() {
  volatile long long producto = 1;
  for (long long i = 1; i <= 30;
       ++i) {  // Smaller loop for multiplication to avoid overflow quickly
    producto *= i;
  }
  return (int)(producto % 256);
}
