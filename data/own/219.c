// 219.c
// Manipulación de array (variación 1)
#define ARRAY_SIZE_219 512
int main() {
  volatile long long array[ARRAY_SIZE_219];
  for (int iter = 0; iter < 200; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_219; ++i) {
      array[i] = i * i + iter * 3;
    }
    for (int i = ARRAY_SIZE_219 - 1; i >= 0; --i) {
      if (i > 0) array[i - 1] += array[i] % (iter + 17);
    }
  }
  return (int)(array[0] % 256);
}
