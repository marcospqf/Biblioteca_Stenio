const ll M = 1000004099;
const ll B = 31;
ll int_mod(ll a, ll b) { return (a % b + b) % b; }
ll eleva(ll a, ll b, ll mod)
{
  if (b == 0)
    return 1;
  else if (b == 1)
    return a;
  ll x = eleva(a, b / 2, mod);
  if (b % 2 == 0)
    return (x * x) % mod;
  else
    return (a * ((x * x) % mod)) % mod;
}
bool Rabin_karp(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  if (n < m) return false;
  ll hp = 0;
  for (int i = 0; i < m; i++) hp = int_mod(hp * B + pattern[i], M);
  ll ht = 0;
  for (int i = 0; i < m; i++) ht = int_mod(ht * B + text[i], M);
  if (ht == hp) return true;
  ll E = eleva(B, m - 1, M);
  for (int i = m; i < n; i++) {
    ht = int_mod(ht - int_mod(text[i - m] * E, M), M);
    ht = int_mod(ht * B, M);
    ht = int_mod(ht + text[i], M);
    if (ht == hp) return true;
  }
  return false;
}
