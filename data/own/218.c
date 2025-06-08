// 218.c
// Manipulación de array (variación 0)
#define ARRAY_SIZE_218 1024
int main() {
  volatile int array[ARRAY_SIZE_218];
  long long suma_total = 0;
  for (int k = 0; k < 500; ++k) {  // Repeat operations multiple times
    for (int i = 0; i < ARRAY_SIZE_218; ++i) {
      array[i] = (i * 7 + k) % 123;
    }
    for (int i = 0; i < ARRAY_SIZE_218; ++i) {
      suma_total += array[i];
    }
  }
  return (int)(suma_total % 256);
}
