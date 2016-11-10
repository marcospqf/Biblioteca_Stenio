//esse crivo gera MAXN primos
const int MAX = 1e6;
int primes[MAX];
void gen_primes()
{
  int i, j;
  for (i = 2; i*i <= MAX; i++)
    if (primes[i])
      for (j = i; j * i < MAX; j++) primes[i * j] = 0;
}
