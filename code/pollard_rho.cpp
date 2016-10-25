ll u;
ll t;
const int tamteste=5;
ll abss(ll v){ return v>=0 ? v : -v;}
ll randerson()
{
  ld pseudo=(ld)rand()/(ld)RAND_MAX;
  return (ll)(round((ld)range*pseudo))+1LL;
}
 
ll mulmod(ll a, ll b, ll mod)
{
  ll ret=0;
  while(b>0)
  {
    if(b%2!=0) ret=(ret+a)%mod;
    a=(a+a)%mod;
    b=b/2LL;
  }
  return ret;
}
 
ll expmod(ll a, ll e, ll mod)
{
  ll ret=1;
  while(e>0)
  {
    if(e%2!=0) ret=mulmod(ret,a,mod);
    a=mulmod(a,a,mod);
    e=e/2LL;
  }
  return ret;
}
bool jeova(ll a, ll n)
{
  ll x = expmod(a,u,n);
  ll last=x;
  for(int i=0;i<t;i++)
  {
    x=mulmod(x,x,n);
    if(x==1 and last!=1 and last!=(n-1)) return true;
    last=x;
  }
  if(x==1) return false;
  return true;
}
 
bool isprime(ll n)
{
 
  u=n-1;
  t=0;
  while(u%2==0)
  {
    t++;
    u/=2LL;
  }
  if(n==2) return true;
  if(n==3) return true;
  if(n%2==0) return false;
  if(n<2) return false;
  for(int i=0;i<tamteste;i++)
  {
    ll v = randerson()%(n-2)+1;
    //cout<<"jeova "<<v<<" "<<n<<endl;
    if(jeova(v,n)) return false;
  }
  return true;
}
 
ll gcd(ll a, ll b){ return !b ? a : gcd(b,a%b);}
 
ll calc(ll x, ll n, ll c)
{
  return (mulmod(x,x,n)+c)%n;
}
ll pollard(ll n)
{
  ll d=1;
  ll i=1;
  ll k=1;
  ll x=2;
  ll y=x;
  ll c;
  do
  {
    c=randerson()%n;
  }while(c==0 or (c+2)%n==0);
  while(d!=n)
  {
    if(i==k)
    {
        k*=2LL;
        y=x;
        i=0;
    }
    x=calc(x,n,c);
    i++;
    d=gcd(abss(y-x),n);
    if(d!=1) return d;
  }
}
 
vector<ll> getdiv(ll n)
{
  vector<ll> ret;
  if(n==1) return ret;
  if(isprime(n))
  {
    ret.pb(n);
    return ret;
  }
  ll d = pollard(n);
  ret=getdiv(d);
  vector<ll> ret2=getdiv(n/d);
  for(int i=0;i<ret2.size();i++) ret.pb(ret2[i]);
  return ret;
}

