struct dificil {
  ld real;
  ld im;
  dificil() {
    real = 0.0;
    im = 0.0;
  }

  dificil(ld real, ld im) : real(real), im(im) {}

  dificil operator+(const dificil &o) const {
    return dificil(o.real + real, im + o.im);
  }

  dificil operator/(ld v) const { return dificil(real / v, im / v); }

  dificil operator*(const dificil &o) const {
    return dificil(real * o.real - im * o.im, real * o.im + im * o.real);
  }

  dificil operator-(const dificil &o) const {
    return dificil(real - o.real, im - o.im);
  }
};

vector<dificil> w[2];
void Pre(int n) {
  w[0].resize(n + 1);
  w[1].resize(n + 1);
  w[0][0] = dificil(1.0, 0.0);
  w[0][1] = dificil(cos(2.0 * pi / (ld)n), sin(2.0 * pi / (ld)n));

  w[1][0] = dificil(1.0, 0.0);
  w[1][1] = dificil(cos(-2.0 * pi / (ld)n), sin(-2.0 * pi / (ld)n));

  for (int i = 2; i <= n; i++)
    if (i & (i - 1))
      w[0][i] = w[0][i & (i - 1)] * w[0][i & -i];
    else
      w[0][i] = w[0][i >> 1] * w[0][i >> 1];

  for (int i = 2; i <= n; i++)
    if (i & (i - 1))
      w[1][i] = w[1][i & (i - 1)] * w[1][i & -i];
    else
      w[1][i] = w[1][i >> 1] * w[1][i >> 1];
}

void fft(vector<dificil> &A, int s) {
  int n = A.size(), p = 0;

  while (n > 1) {
    p++;
    n >>= 1;
  }
  n = (1 << p);
  if (w[0].size() == 0)
    Pre(n);
  vector<dificil> a = A;

  for (int i = 0; i < n; ++i) {
    int rev = 0;
    for (int j = 0; j < p; ++j) {
      rev <<= 1;
      rev |= ((i >> j) & 1);
    }
    A[i] = a[rev];
  }

  int ntmp = n;
  for (int i = 1; i <= p; ++i) {
    int M = 1 << i;
    int K = M >> 1;
    ntmp >>= 1;
    for (int j = 0; j < n; j += M) {
      for (int l = j; l < K + j; ++l) {
        dificil t = w[s][(ntmp * (l - j)) % n];
        t = t * A[l + K];
        dificil u = A[l];
        A[l] = A[l] + t;
        u = u - t;
        A[l + K] = u;
      }
    }
  }

  if (s == 1) {
    for (int i = 0; i < n; ++i)
      A[i] = A[i] / (ld)n;
  }
}
void mul(vector<dificil> &a, vector<dificil> &b) {
  for (int i = 0; i < (int)a.size(); i++) {
    a[i] = a[i] * b[i];
  }
}
