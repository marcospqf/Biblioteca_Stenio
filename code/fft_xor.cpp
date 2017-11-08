/*
  Walsh-Hadamard Matrix :
  1 1
  1 -1
  Inverse : 
  1 1
  1 -1
  v.size() power of 2
  usage:
  fft_xor(a, false);
  fft_xor(b, false);
  mul(a, b);
  fft_xor(a, true);
*/

void fft_xor(vi &a, bool inv) {
  vi ret = a;
  ll u, v;
  int tam = a.size() / 2;
  for(int len = 1; 2 * len <= tam; len <<= 1) {
    for(int i = 0; i < tam; i += 2 * len) {
      for(int j = 0; j < len; j++) {
        u = ret[i + j];
        v = ret[i + len + j];
        ret[i + j] = u + v;
        ret[i + len + j] = u - v;
      }
    }
  }
  if(inv) {
    for(int i = 0; i < tam; i++) {
      ret[i] /= tam;
    }
  }
  a = ret;
}

