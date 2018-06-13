template <class T> struct Bit {
  vector<T> bit;
  int n;
  Bit(int n_) : n(n_), bit(n_) {}
  void add(int idx, T val) {
    while (idx < n) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }
  T sum(int idx) {
    T ret = 0;
    while (idx > 0) {
      ret += bit[idx];
      idx -= idx & -idx;
    }
    return ret;
  }
  T query(int L, int R) {
    T ret = sum(R);
    if (L > 0)
      ret -= sum(L - 1);
    return ret;
  }
};
