/*
 * O(nlog^2(n)) para o sufix array 
 * O(logn) para o LCP(i,j)
 * LCP de i para j;
 */
struct SA {
  const int L;
  string s;
  vvi P;
  vector<pair< ii,int> > M;

  SA(const string &s) : L(s.size()), s(s), P(1, vi(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] =s[i]-'a';
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.pb(vi(L, 0));
      for (int i = 0; i < L; i++) 
        M[i] = mp(mp(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++) 
        P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }    
  }

  vi GetSA() { 
    vi v=P.back();
    vi ret(v.size());
    for(int i=0;i<v.size();i++){
      ret[v[i]]=i;
    }
    return ret; 
  }
  int LCP(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
        i += 1 << k;
        j += 1 << k;
        len += 1 << k;
      }
    }
    return len;
  }
  vi GetLCP(vi &sa)
  {
    vi lcp(sa.size()-1);
    for(int i=0;i<sa.size()-1;i++){
      lcp[i]=LCP(sa[i],sa[i+1]);
    }
    return lcp;
  }
};
