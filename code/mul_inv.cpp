//inverso multiplicativo de A % MOD
//certifique de MOD estar definido antes bonito!
//complexidade: O(log(a))
ll mul_inv(ll a)
{
  ll pin0 = MOD, pin = MOD, t, q;
  ll x0 = 0, x1 = 1;
  if (pin == 1) return 1;
  while (a > 1) {
    q = a / pin;
    t = pin, pin = a % pin, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  if (x1 < 0) x1 += pin0;
  return x1;
}
