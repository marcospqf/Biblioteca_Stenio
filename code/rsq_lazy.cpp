//RSQ COM LAZY PROPAGATION!
class RSQ {
 private:
  vll A;
  vll M;
  vll lazy;

 public:
  RSQ(vll &v)
  {
    A = v;
    M.resize(v.size() * 4);
    lazy.assign(v.size() * 4, 0);
    build(1, 0, v.size() - 1);
  }
  void build(int node, int b, int e)
  {
    if (b == e) {
      M[node] = A[b];
      return;
    }
    build(2 * node, b, (b + e) / 2);
    build(2 * node + 1, (b + e) / 2 + 1, e);
    M[node] = M[2 * node] + M[2 * node + 1];
  }
  void atualiza(int node, int b, int e, int i, int j, ll val)
  {
    if (lazy[node] != 0) {
      M[node] += lazy[node];
      if (b != e) {
        ll inter = (e - b + 1);
        ll i1 = (b + e) / 2 - b + 1;
        ll i2 = e - (b + e) / 2;
        ll un = lazy[node] / inter;
        lazy[2 * node] += un * i1;
        lazy[2 * node + 1] += un * i2;
      }
      lazy[node] = 0;
    }
    if (i > e or j < b) return;
    if (i <= b and j >= e) {
      ll inter = (e - b + 1);
      M[node] += val * inter;
      if (b != e) {
        ll i1 = (b + e) / 2 - b + 1;
        ll i2 = e - (b + e) / 2;
        lazy[2 * node] += i1 * (ll)val;
        lazy[2 * node + 1] += i2 * (ll)val;
      }
      return;
    }
    atualiza(2 * node, b, (b + e) / 2, i, j, val);
    atualiza(2 * node + 1, (b + e) / 2 + 1, e, i, j, val);
    M[node] = M[2 * node] + M[2 * node + 1];
  }
  ll query(int node, int b, int e, int i, int j)
  {
    if (i > e or j < b) return 0;
    ll p1, p2;
    if (lazy[node] != 0) {
      M[node] += lazy[node];
      if (b != e) {
        ll inter = (e - b + 1);
        ll i1 = (b + e) / 2 - b + 1;
        ll i2 = e - (b + e) / 2;
        ll un = lazy[node] / inter;
        lazy[2 * node] += un * i1;
        lazy[2 * node + 1] += un * i2;
      }
      lazy[node] = 0;
    }
    if (i <= b and j >= e) return M[node];
    p1 = query(2 * node, b, (b + e) / 2, i, j);
    p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j);
    return p1 + p2;
  }
};
