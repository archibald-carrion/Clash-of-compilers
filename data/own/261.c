// 261.c
// Operaciones bitwise en un bucle (variación 8)
int main() {
  volatile unsigned int data = 0xFEEDFACE;
  for (long long i = 0; i < 2300000; ++i) {
    data = (data & 0xFFFFFF00) | ((data + (unsigned int)i) % 0xFF);
    data = (data >> (i % 4)) | (data << (32 - (i % 4)));
  }
  return (int)(data % 256);
}
