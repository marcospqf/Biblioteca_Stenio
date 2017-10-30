/* parametros finais:
a -> gcd(a, b)
x -> "inverso aritmetico" de a mod b
y -> "inverso aritmetico" de b mod a
resolve d = ax + by
para outras solucoes:
x + t * b / d
y - t * a / d */

int extended_euclid(int a, int b, int &x, int &y)
{
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a / b;
    int t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
