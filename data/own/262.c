// 262.c
// Operaciones bitwise en un bucle (variación 9)
int main() {
  volatile unsigned long long state = 0xABCDEF0123456789ULL;
  for (long long i = 0; i < 1700000; ++i) {
    state += 0x9E3779B97F4A7C15ULL;  // Constant from TEA algorithm
    unsigned long long temp = state;
    temp = (temp ^ (temp >> 30)) * 0xBF58476D1CE4E5B9ULL;
    temp = (temp ^ (temp >> 27)) * 0x94D049BB133111EBULL;
    state ^= temp >> 31;
  }
  return (int)(state % 256);
}
