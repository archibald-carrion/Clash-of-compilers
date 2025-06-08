// 254.c
// Lógica condicional en bucle (variación 5)
int main() {
  volatile double val = 1.0;
  for (long long i = 1; i <= 2000000; ++i) {
    if ((long long)val % 2 == 0 && i % 2 == 0) {
      val += (double)i / ((val > 0 ? val : 1.0) * 0.5);
    } else {
      val -= (double)i / ((val < 0 ? val : -1.0) * 0.5);
    }
    if (val > 1e12) val = 1.0;
    if (val < -1e12) val = -1.0;
    if (val == 0.0) val = i;  // Avoid division by zero if val becomes exactly 0
  }
  return (int)((long long)val % 256);
}
