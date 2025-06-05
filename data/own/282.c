// 282.c
// Suma/resta aritmética en un bucle (variación 14)
int main() {
  volatile float f_sum = 0.0f;
  for (long long i = 1; i <= 1600000; ++i) {
    f_sum += (float)(i % 1000) / ((i % 100) + 1.0f) - 10.0f;
    if (f_sum > 100000.0f) f_sum -= 200000.0f;
    if (f_sum < -100000.0f) f_sum += 200000.0f;
  }
  return (int)((long long)f_sum % 256);
}
