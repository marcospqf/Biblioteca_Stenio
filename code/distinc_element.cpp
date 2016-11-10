const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
int bit[N], v[N], id[N], r[N];
ii query[N];
int mapa[N];
bool compare(int x, int y) { return query[x] < query[y]; }
void add(int idx, int val)
{
  while (idx < N) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
int sum(int idx)
{
  int ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}
int main()
{
  memset(bit, 0, sizeof(bit));
  memset(mapa, 0, sizeof(mapa));
  int n;
  sc(n);
  for (int i = 1; i <= n; i++) sc(v[i]);
  int q;
  sc(q);
  for (int i = 0; i < q; i++) {
    sc2(query[i].second, query[i].first);
    id[i] = i;
  }
  sort(id, id + q, compare);
  sort(query, query + q);
  int j = 1;
  for (int i = 0; i < q; i++) {
    int L = query[i].second;
    int R = query[i].first;
    while (j <= R) {
      if (mapa[v[j]] > 0) {
        add(mapa[v[j]], -1);
        mapa[v[j]] = j;
        add(mapa[v[j]], 1);
      }
      else {
        mapa[v[j]] = j;
        add(mapa[v[j]], 1);
      }
      j++;
    }
    r[id[i]] = sum(R);
    if (L > 1) r[id[i]] -= sum(L - 1);
  }
  for (int i = 0; i < q; i++) pri(r[i]);
  return 0;
}
