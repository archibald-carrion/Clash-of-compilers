// 299.c
// Manipulación de array (variación 15) - Final type 4
#define ARRAY_SIZE_299 768
int main() {
  volatile int data[ARRAY_SIZE_299];
  long long sum_of_medians = 0;
  for (int iter = 0; iter < 200; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_299; ++i)
      data[i] = (int)((iter * 5 + i * 3 + (iter * i) % 101) % 10000 - 5000);
    // Simple sort for 3 elements to find median-of-3, then sum
    for (int i = 0; i < ARRAY_SIZE_299 - 2; i += 3) {
      int a = data[i], b = data[i + 1], c = data[i + 2];
      int med = (a > b) ? ((b > c) ? b : (a > c ? c : a))
                        : ((a > c) ? a : (b > c ? c : b));
      sum_of_medians += med;
    }
  }
  return (int)(sum_of_medians % 256);
}
