// 241.c
// Lógica condicional en bucle (variación 3)
int main() {
  volatile long long val = 5555;
  for (long long i = 1; i <= 3500000; ++i) {
    switch (i % 4) {
      case 0:
        val += i / 2;
        break;
      case 1:
        val -= i * 2;
        break;
      case 2:
        if (val != 0) val /= ((i % 3) + 1);
        break;
      case 3:
        val *= (i % 5) + 1;
        break;
    }
    if (val > 100000000000LL) val = i;
    if (val < -100000000000LL) val = -i;
  }
  return (int)(val % 256);
}
