// 252.c
// Manipulación de array (variación 8)
#define ARRAY_SIZE_252 4096
int main() {
  volatile unsigned char array[ARRAY_SIZE_252];
  unsigned int counts[256] = {0};
  for (int iter = 0; iter < 50; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_252; ++i) {
      array[i] = (unsigned char)((i * iter * 13 + 12345) % 256);
    }
    for (int i = 0; i < ARRAY_SIZE_252; ++i) {
      counts[array[i]]++;
    }
  }
  long long final_val = 0;
  for (int i = 0; i < 256; ++i) final_val += counts[i] * i;
  return (int)(final_val % 256);
}
