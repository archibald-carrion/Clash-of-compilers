// 231.c
// Operaciones mixtas (variación 1)
int main() {
  volatile double acc_d = 789.123;
  for (long long i = 1; i <= 900000; ++i) {
    acc_d += (double)(i % 123) / 3.14;
    if (((int)i % 200) == 0) {
      acc_d *= 0.99;
    }
    if (acc_d > 1e10)
      acc_d = 789.123;
    else if (acc_d < 1e-5 && acc_d != 0)
      acc_d = 1.0;
  }
  return (int)((long long)acc_d % 256);
}
