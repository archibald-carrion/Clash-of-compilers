// 246.c
// Multiplicación/división en un bucle (variación 6)
int main() {
  volatile long long producto = 2;
  for (long long i = 1; i <= 32; ++i) {
    producto *= (i + producto % 5);  // Dependency on previous product value
    if (producto > 100000000000000000LL)
      producto = i;  // Prevent extreme overflow
  }
  return (int)(producto % 256);
}
