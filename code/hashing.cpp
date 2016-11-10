//certificar que gethash() foi chamado 
//antes de getHash(i,j);
struct Hashing {
  const string &s;
  int n, idx;
  vector<ll> hashes,M,B;
  Hashing(const string &s) : s(s), hashes(s.size()){
    M={1000000409, 2000003273, 2000003281, 2000003293};
    B={31, 53, 61, 41};
    srand(time(NULL));
    idx=rand()%4;
    getHash();
  }
  void otherprime(){
    idx=(idx+1)%4;
  }
  ll int_mod(ll a) { return (a % M[idx] + M[idx]) % M[idx]; }
  ll eleva(ll a, ll b)
  {
    if (b == 0)
      return 1;
    else if (b == 1)
      return a;
    ll x = eleva(a, b / 2);
    if (b % 2 == 0)
      return (x * x) % M[idx];
    else
      return (a * ((x * x) % M[idx])) % M[idx];
  }
  /*hash da string de 0 ate i*/
  void getHash()
  {
    int n = s.size();
    ll hp = 0;
    for (int i = 0; i < s.size(); i++) {
      hp = int_mod(hp * B[idx] + s[i]);
      hashes[i] = hp;
    }
  }
  /*Hash da string compreendida entre i e j*/
  ll getHash(int i, int j)
  {
    if (i == 0) return hashes[j];
    ll h1 = hashes[j];
    ll h2 = (hashes[i - 1] * eleva(B[idx],j - i+1)) % M[idx];
    ll ret = (h1 - h2) % M[idx] + M[idx];
    return ret % M[idx];
  }
};
