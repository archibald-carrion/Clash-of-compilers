// 242.c
// Operaciones mixtas (variación 2)
int main() {
  volatile unsigned int acc_ui = 98765;
  for (long long i = 1; i <= 1000000; ++i) {
    acc_ui -= (unsigned int)(i % 2500);
    acc_ui = (acc_ui << (i % 3)) | (acc_ui >> (32 - (i % 3)));
    if (i % 150 == 0) {
      acc_ui *= ((i % 7) + 2);
    }
  }
  return (int)(acc_ui % 256);
}
