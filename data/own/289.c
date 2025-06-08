// 289.c
// Lógica condicional en bucle (variación 10)
int main() {
  volatile long long p = 23, q = 29, n = p * q, phi_n = (p - 1) * (q - 1);
  volatile long long e = 3, d = 0, k = 1;
  // Simplified modular inverse for d (RSA-like setup, but not actual crypto)
  // d*e = 1 (mod phi_n) -> d = (1 + k*phi_n)/e
  while ((1 + k * phi_n) % e != 0) {
    k++;
  }
  d = (1 + k * phi_n) / e;

  long long msg = 123, c, m_decrypted;
  long long result = 0;

  for (long long iter = 0; iter < 50000; ++iter) {
    msg = (iter % (n - 2)) + 2;  // Vary message
    // Encryption: c = msg^e mod n (simplified, direct power may be too
    // slow/large)
    c = msg;
    for (int i = 1; i < e; i++) c = (c * msg) % n;

    // Decryption: m = c^d mod n
    m_decrypted = c;
    for (int i = 1; i < d; i++) m_decrypted = (m_decrypted * c) % n;

    if (msg == m_decrypted)
      result++;
    else
      result--;
  }
  return (int)(result % 256);
}
