ll mulmod(ll a, ll b, ll m)
{
  ll ret = 0;
  while (b > 0) {
    if (b % 2 != 0) ret = (ret + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return ret;
}
ll expmod(ll a, ll e, ll m)
{
  ll ret = 1;
  while (e > 0) {
    if (e % 2 != 0) ret = mulmod(ret, a, m);
    a = mulmod(a, a, m);
    e >>= 1;
  }
  return ret;
}

ll invmul(ll a, ll m) { return expmod(a, m - 2, m); }
ll chinese(vector<ll> r, vector<ll> m)
{
  int sz = m.size();
  ll M = 1;
  for (int i = 0; i < sz; i++) {
    M *= m[i];
  }
  ll ret = 0;
  for (int i = 0; i < sz; i++) {
    ret += mulmod(mulmod(M / m[i], r[i], M), invmul(M / m[i], M), M);
    ret = ret % M;
  }
  return ret;
}
