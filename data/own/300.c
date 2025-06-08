// 300.c
// Manipulación de array (variación 16)
#define ARRAY_SIZE_300 2048
int main() {
  volatile unsigned char image[ARRAY_SIZE_300];  // Simplified 1D image data
  unsigned int histogram[256] = {0};
  for (int iter = 0; iter < 25; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_300; ++i) {
      image[i] =
          (unsigned char)(((iter + 1) * (i * i) + i * 17 + (iter * 31)) % 256);
    }
    for (int i = 0; i < 256; ++i) histogram[i] = 0;  // Reset histogram
    for (int i = 0; i < ARRAY_SIZE_300; ++i) {
      histogram[image[i]]++;
    }
  }
  unsigned int max_freq = 0;
  for (int i = 0; i < 256; ++i)
    if (histogram[i] > max_freq) max_freq = histogram[i];
  return (int)(max_freq % 256);
}
