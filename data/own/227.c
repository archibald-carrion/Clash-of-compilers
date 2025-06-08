// 227.c
// Manipulación de array (variación 2)
#define ARRAY_SIZE_227 2048
int main() {
  volatile char array[ARRAY_SIZE_227];
  long long suma_ascii = 0;
  for (int k = 0; k < 300; ++k) {
    for (int i = 0; i < ARRAY_SIZE_227; ++i) {
      array[i] = (char)((i * k + 65) % 26 + 'A');  // Store uppercase letters
    }
    for (int i = 0; i < ARRAY_SIZE_227; ++i) {
      suma_ascii += array[i];
    }
  }
  return (int)(suma_ascii % 256);
}
