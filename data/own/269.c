// 269.c
// Suma/resta aritmética en un bucle (variación 11)
int main() {
  volatile long long suma_total = 0;
  long long current_val = 1;
  for (long long i = 1; i <= 1300000; ++i) {
    current_val += i;
    if (i % 2 == 0)
      suma_total += current_val;
    else
      suma_total -= current_val;
    if (suma_total > 1000000000000LL) suma_total = current_val;
    if (suma_total < -1000000000000LL) suma_total = -current_val;
  }
  return (int)(suma_total % 256);
}
