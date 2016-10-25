struct ext {
  ll x;
  ll y;
  ll mdc;
};
ext tmp;
// ax + by=c, se mdc(a,b) nao divide c, nao tem solucao, caso contrario, x = x0
// // +(b/mdc)*n, y=yo-(a/mdc)*n
ll ee(ll a, ll b, ll &x, ll &y)
{
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll tmp = ee(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return tmp;
}
ext extended_euclid(ll a, ll b)
{
  ll tmp, tmp1;
  ext ret;
  ret.mdc = ee(a, b, tmp, tmp1);
  ret.x = tmp;
  ret.y = tmp1;
  return ret;
}
