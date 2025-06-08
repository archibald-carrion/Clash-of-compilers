// 239.c
// Manipulación de array (variación 5)
#define ARRAY_SIZE_239 768
int main() {
  volatile float array[ARRAY_SIZE_239];
  float max_val = 0.0f;
  for (int iter = 0; iter < 250; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_239; ++i) {
      array[i] = (float)(i * i - iter * 5) / ((i % 10) + 1.0f);
    }
    max_val = array[0];
    for (int i = 1; i < ARRAY_SIZE_239; ++i) {
      if (array[i] > max_val) max_val = array[i];
    }
  }
  return (int)((long long)max_val % 256);
}
