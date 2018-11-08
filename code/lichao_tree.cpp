#include <bits/stdc++.h>
#define LL long long
#define lc (x << 1)
#define rc (x << 1 | 1)
#define INF 0x7FFFFFFF // or 0x3f3f3f3f ?
using namespace std;
/*============ Header Template ============*/

const int N = 100000 + 5;

int n, m;
int vis[N << 1];
char op[100];

struct line {
  double k, b;
  line(double _k = 0, double _b = 0) {
    k = _k;
    b = _b;
  }
  double get(double x) { return k * x + b; }
} c[2 * N];

///
void modify(int x, int l, int r, line v) {
  if (!vis[x]) {
    vis[x] = 1;
    c[x] = v;
    return;
  }
  if (c[x].get(l) > v.get(l) && c[x].get(r) > v.get(r))
    return;
  if (c[x].get(l) < v.get(l) && c[x].get(r) < v.get(r)) {
    c[x] = v;
    return;
  }
  int m = (l + r) >> 1;
  if (c[x].get(l) < v.get(l))
    swap(c[x], v);
  if (c[x].get(m) > v.get(m))
    modify(rc, m + 1, r, v);
  else {
    swap(c[x], v);
    modify(lc, l, m, v);
  }
}

double get(int x, int l, int r, int pos) {
  if (l == r)
    return c[x].get(l);
  int m = (l + r) >> 1;
  double ans = c[x].get(pos);
  if (pos <= m)
    ans = max(ans, get(lc, l, m, pos));
  else
    ans = max(ans, get(rc, m + 1, r, pos));
  return ans;
}
