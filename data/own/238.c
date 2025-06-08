// 238.c
// Manipulación de array (variación 4)
#define ARRAY_SIZE_238 1536
int main() {
  volatile short array[ARRAY_SIZE_238];
  long long producto_total = 1;
  for (int k = 0; k < 400; ++k) {
    for (int i = 0; i < ARRAY_SIZE_238; ++i) {
      array[i] = (short)((i * 5 + k * 2) % 30000);
    }
    for (int i = 0; i < ARRAY_SIZE_238;
         i += 2) {  // Accessing alternate elements
      if (array[i] != 0)
        producto_total = (producto_total * array[i]) % 1000000007;
      if (producto_total == 0) producto_total = 1;
    }
  }
  return (int)(producto_total % 256);
}
