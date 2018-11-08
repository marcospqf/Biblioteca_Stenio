/*p = 998244353
factors = [2, 7, 17] # fatores de p-1
# testa se g eh raiz primitiva
for f in factors:
    if pow(g, (p-1)/f, p) == 1:
        print "Nao eh raiz"*/
typedef long long LL;
const int N = 300005;
const int P = 998244353;
const int inf = 1e9;
const LL Inf = 1e18;
int n, p[N], rev[N];
LL k;
const int G = 3;
int w[2][N], tn, tl;

void dft(int *a, int f) {
  FOR(i, 0, tn) if (i < rev[i]) swap(a[i], a[rev[i]]);

  for (int i = 1; i < tn; i <<= 1)
    for (int j = 0, t = tn / (i << 1); j < tn; j += i << 1)
      for (int k = 0, l = 0; k < i; k++, l += t) {
        int x = a[j + k];
        int y = (LL)a[j + k + i] * w[f][l] % P;
        a[j + k] = (x + y) % P;
        a[j + k + i] = (x + P - y) % P;
      }

  if (f) {
    int rn = Pow(tn, P - 2, P);
    FOR(i, 0, tn) a[i] = (LL)a[i] * rn % P;
  }
}

int A[N], B[N], fac[N], ifac[N], T[N];

void prep(int n) {
  for (tn = 1, tl = -1; tn <= (n * 2); tn <<= 1, tl++)
    ;

  w[0][0] = w[1][0] = 1;
  int ng = Pow(3, (P - 1) / tn, P);
  FOR(i, 1, tn) {
    w[0][i] = (LL)w[0][i - 1] * ng % P;
    w[1][i] = Pow(w[0][i], P - 2, P);
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << tl);
  }
}
