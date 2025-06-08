// 289.c
// Lógica condicional en bucle (variación 10)
#include <stdlib.h>

long long logica_condicional_var10() {
  long long* p = malloc(sizeof(long long));
  long long* q = malloc(sizeof(long long));
  long long* n = malloc(sizeof(long long));
  long long* phi_n = malloc(sizeof(long long));
  long long* e = malloc(sizeof(long long));
  long long* d = malloc(sizeof(long long));
  long long* k = malloc(sizeof(long long));

  if (!p || !q || !n || !phi_n || !e || !d || !k) {
    free(p);
    free(q);
    free(n);
    free(phi_n);
    free(e);
    free(d);
    free(k);
    return 0;
  }

  *p = 23;
  *q = 29;
  *n = (*p) * (*q);
  *phi_n = ((*p) - 1) * ((*q) - 1);
  *e = 3;
  *d = 0;
  *k = 1;

  // Simplified modular inverse for d (RSA-like setup, but not actual crypto)
  // d*e = 1 (mod phi_n) -> d = (1 + k*phi_n)/e
  while ((1 + (*k) * (*phi_n)) % (*e) != 0) {
    (*k)++;
  }
  *d = (1 + (*k) * (*phi_n)) / (*e);

  long long* msg = malloc(sizeof(long long));
  long long* c = malloc(sizeof(long long));
  long long* m_decrypted = malloc(sizeof(long long));
  long long* result = malloc(sizeof(long long));

  if (!msg || !c || !m_decrypted || !result) {
    free(p);
    free(q);
    free(n);
    free(phi_n);
    free(e);
    free(d);
    free(k);
    free(msg);
    free(c);
    free(m_decrypted);
    free(result);
    return 0;
  }

  *msg = 123;
  *result = 0;

  for (long long iter = 0; iter < 50000; ++iter) {
    *msg = (iter % ((*n) - 2)) + 2;  // Vary message
    // Encryption: c = msg^e mod n (simplified, direct power may be too
    // slow/large)
    *c = *msg;
    for (int i = 1; i < *e; i++) *c = ((*c) * (*msg)) % (*n);

    // Decryption: m = c^d mod n
    *m_decrypted = *c;
    for (int i = 1; i < *d; i++) *m_decrypted = ((*m_decrypted) * (*c)) % (*n);

    if (*msg == *m_decrypted)
      (*result)++;
    else
      (*result)--;
  }

  long long final_result = (*result) % 256;
  free(p);
  free(q);
  free(n);
  free(phi_n);
  free(e);
  free(d);
  free(k);
  free(msg);
  free(c);
  free(m_decrypted);
  free(result);
  return final_result;
}

int main() {
  logica_condicional_var10();
  return 0;
}
