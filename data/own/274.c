// 274.c
// Operaciones bitwise en un bucle (variación 11)
// Simulating a Linear Feedback Shift Register (LFSR)
int main() {
  volatile unsigned long long lfsr = 0xACE1uLL;  // Non-zero start
  unsigned long long period = 0;
  for (long long i = 0; i < 1500000; ++i) {
    unsigned lsb = lfsr & 1uLL;  // Get LSB
    lfsr >>= 1;                  // Shift right
    if (lsb) {                   // If LSB is 1, apply XOR mask
      lfsr ^= 0xB400uLL;         // Taps for 16-bit, common for PRNG
    }
    period++;  // Not really period, just a counter for work
  }
  return (int)((lfsr + period) % 256);
}
