//RMQ DE INDICE 
class RMQ {
 private:
  vi A;
  vi M;
 public:
  RMQ(vi &v)
  {
    A = v;
    M.resize(4 * v.size());
    build(1, 0, v.size() - 1);
  }
  void build(int node, int b, int e)
  {
    if (b == e)
      M[node] = b;
    else {
      build(2 * node, b, (b + e) / 2);
      build(2 * node + 1, (b + e) / 2 + 1, e);
      if (A[M[2 * node]] <= A[M[2 * node + 1]])
        M[node] = M[2 * node];
      else
        M[node] = M[2 * node + 1];
    }
  }
  int query(int node, int b, int e, int i, int j)
  {
    int p1, p2;
    if (i > e || j < b) return -1;
    if (b >= i and e <= j) return M[node];
    p1 = query(2 * node, b, (b + e) / 2, i, j);
    p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    if (A[p1] <= A[p2]) return p1;
    return p2;
  }

  void atualiza(int node, int b, int e, int i, int val)
  {
    if (i > e || i < b) return;
    if (e == b) {
      A[i] = val;
    }
    else {
      atualiza(2 * node, b, (b + e) / 2, i, val);
      atualiza(2 * node + 1, (b + e) / 2 + 1, e, i, val);
      if (A[M[2 * node]] <= A[M[2 * node + 1]])
        M[node] = M[2 * node];
      else
        M[node] = M[2 * node + 1];
    }
  }
};
