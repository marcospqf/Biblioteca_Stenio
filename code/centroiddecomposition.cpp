#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define imprime(v) for(int X=0;X<v.size();X++) printf("%d ", v[X]); printf("\n");
#define endl "\n"
const int INF= 0x3f3f3f3f;
const long double pi= acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vector< int > > vvi;
const int MOD=1e9+7;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int MAXN = 50005;
vi g[MAXN];
int forb[MAXN];
int sz[MAXN];
int pai[MAXN];
int n, m;
unordered_map<int, int> dist[MAXN];


void dfs(int u, int last) {
  sz[u] = 1;
  for(int v : g[u]) {
    if(v != last and !forb[v]) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

int find_cen(int u, int last, int qt) {
  int ret = u;
  for(int v : g[u]) {
    if(v == last or forb[v]) continue;
    if(sz[v] > qt / 2) return find_cen(v, u, qt);
  }
  return ret;
}

void getdist(int u, int last, int cen) {
  for(int v : g[u]) {
    if(v != last and !forb[v]) {
      dist[cen][v] = dist[v][cen] = dist[cen][u] + 1;
      getdist(v, u, cen);
    }
  }
}


void decomp(int u, int last) {
  dfs(u, -1);
  int qt = sz[u];
  int cen = find_cen(u, -1, qt);
  forb[cen] = 1;
  pai[cen] = last;
  dist[cen][cen] = 0;
  getdist(cen, -1, cen);
  for(int v : g[cen]) {
    if(!forb[v]) {
      decomp(v, cen);
    }
  }
}

int main() {
  sc2(n, m);

  for(int i = 0; i < n - 1; i++) {
    int a, b;
    sc2(a, b);
    g[a].pb(b);
    g[b].pb(a);
  }
  
  decomp(1, -1);
  return 0;
}
