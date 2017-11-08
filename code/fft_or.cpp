/*
  Matrix :
  1 1
  1 0
  Inverse : 
  0 1
  1 -1
  v.size() power of 2
  usage:
  fft_or(a, false);
  fft_or(b, false);
  mul(a, b);
  fft_or(a, true);
*/

void fft_or(vi &a, bool inv) {
  vi ret = a;
  ll u, v;
  int tam = a.size() / 2;
  for(int len = 1; 2 * len <= tam; len <<= 1) {
    for(int i = 0; i < tam; i += 2 * len) {
      for(int j = 0; j < len; j++) {
        u = ret[i + j];
        v = ret[i + len + j];
        if(!inv) {
          ret[i + j] = u + v;
          ret[i + len + j] = u;
        }
        else {
          ret[i + j] = v;
          ret[i + len + j] = u - v;
        }
      }
    }
  }
  a = ret;
}

void mul(vi &a, vi &b) {
  for(int i = 0; i < a.size(); i++) {
    a[i] = a[i] * b[i];
  }
}
