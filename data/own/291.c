// 291.c
// Operaciones mixtas (variación 10)
// Simple checksum-like calculation on generated data
int main() {
  volatile unsigned int checksum = 0;
  volatile unsigned char current_byte = 0;
  for (long long i = 0; i < 2000000; ++i) {
    current_byte =
        (unsigned char)((i * 17 + (i >> 12) + (checksum & 0xFF)) % 256);
    checksum = (checksum << 1) | (checksum >> 31);  // Rotate left
    checksum ^= current_byte;
    if (i % 10000 == 0) {
      checksum += 0x12345678;
    }
  }
  return (int)(checksum % 256);
}
