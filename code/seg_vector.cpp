//compilar em C++11, essa segment tree
//computa qual e o k's elemento compreendido
//no intervalo entre i,j
//presentes no array
vi tr[5 * N];
void build(int node, int b, int e)
{
  if (b == e)
    tr[node].pb(v[b]);
  else {
    build(2 * node, b, (b + e) / 2);
    build(2 * node + 1, (b + e) / 2 + 1, e);
    merget(tr[2 * node], tr[2 * node + 1], tr[node]);
    merge(tr[2 * node].begin(), tr[2 * node].end(), tr[2 * node + 1].begin(),
          tr[2 * node + 1].end(), back_inserter(tr[node]));
  }
}
int query(int node, int b, int e, int i, int j, int k)
{
  if (i > e or b > j) return 0;
  if (i <= b and j >= e) {
    int resp =
        upper_bound(tr[node].begin(), tr[node].end(), k) - tr[node].begin();
    return tr[node].size() - resp;
  }
  return query(2 * node, b, (b + e) / 2, i, j, k) +
         query(2 * node + 1, (b + e) / 2 + 1, e, i, j, k);
}
