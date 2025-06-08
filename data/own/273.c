// 273.c
// Operaciones bitwise en un bucle (variación 10)
int main() {
  volatile unsigned int flags = 0xAAAAAAAA;
  for (long long i = 0; i < 2400000; ++i) {
    int bit_pos = i % 32;
    if ((i / 32) % 2 == 0)
      flags |= (1U << bit_pos);  // Set bit
    else
      flags &= ~(1U << bit_pos);       // Clear bit
    if (i % 100 == 0) flags = ~flags;  // Toggle all bits
  }
  return (int)(flags % 256);
}
