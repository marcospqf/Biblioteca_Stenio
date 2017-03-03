//PRINTAR O NUMERO DE ELEMENTOS DISTINTOS 
//EM UM INTERVALO DO ARRAY
const int N = 30010;
int tr[100 * N], L[100 * N], R[100 * N], root[100 * N];
int v[N], mapa[100 * N];
int cont = 0;
void build(int node, int b, int e)
{
  if (b == e) {
    tr[node] = 0;
  }
  else {
    L[node] = cont++;
    R[node] = cont++;
    build(L[node], b, (b + e) / 2);
    build(R[node], (b + e) / 2 + 1, e);
    tr[node] = tr[L[node]] + tr[R[node]];
  }
}
int update(int node, int b, int e, int i, int val)
{
  int idx = cont++;
  tr[idx] = tr[node] + val;
  L[idx] = L[node];
  R[idx] = R[node];
  if (b == e) return idx;
  int mid = (b + e) / 2;
  if (i <= mid)
    L[idx] = update(L[node], b, mid, i, val);
  else
    R[idx] = update(R[node], mid + 1, e, i, val);
  return idx;
}
int query(int nodeL, int nodeR, int b, int e, int i, int j)
{
  if (b > j or i > e) return 0;
  if (i <= b and j >= e) {
    int p1 = tr[nodeR];
    int p2 = tr[nodeL];
    return p1 - p2;
  }
  int mid = (b + e) / 2;
  return query(L[nodeL], L[nodeR], b, mid, i, j) +
         query(R[nodeL], R[nodeR], mid + 1, e, i, j);
}
int main()
{
  int n;
  sc(n);
  memset(mapa, -1, sizeof(mapa));
  for (int i = 0; i < n; i++) sc(v[i]);
  build(1, 0, n - 1);
  for (int i = 0; i < n; i++) {
    if (mapa[v[i]] == -1) { 
      root[i + 1] = update(root[i], 0, n - 1, i, 1);
      mapa[v[i]] = i;
    }
    else {
      root[i + 1] = update(root[i], 0, n - 1, mapa[v[i]], -1);
      mapa[v[i]] = i;
      root[i + 1] = update(root[i + 1], 0, n - 1, i, 1);
    }
  }
  int q;
  sc(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    sc2(l, r);
    int resp = query(root[l - 1], root[r], 0, n - 1, l - 1, r - 1);
    pri(resp);
  }
  return 0;
}
