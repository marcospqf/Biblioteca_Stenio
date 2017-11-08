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
typedef pair<int, double> ii;
typedef vector<int> vi;
typedef vector< vector< int > > vvi;
const int MOD=1e9+7;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int MAXN = 3505;
/*
  s e t pre-definidos como MAXN - 1 e MAXN - 2.
  cnt_nodes é qual o maior indice que voce usou. Caso nao saiba, use MAXN - 1.
  IMPORTANTE: DEFINA CNT_NODES antes de usar. Se nao, nao funciona.
  minCostFlow(f) computa o par (fluxo, custo) com o menor custo passando fluxo <= f de fluxo.
  Se passar INF, computa o fluxo maximo.
*/
struct edge
{
  int to, rev, flow, cap, cost;
  edge() { to = 0; rev = 0; flow = 0; cap = 0; cost = 0; }
  edge(int _to, int _rev, int _flow, int _cap, int _cost)
  {
    to = _to; rev = _rev;
    flow = _flow; cap = _cap;
    cost = _cost;
  }
};

struct MCMF {

  int cnt_nodes = 0, s = MAXN - 1, t = MAXN - 2;
  vector<edge> G[MAXN];

  void addEdge(int u, int v, int w, int cost)
  {
    edge t = edge(v, G[v].size(), 0, w, cost);
    edge r = edge(u, G[u].size(), 0, 0, -cost);

    G[u].push_back(t);
    G[v].push_back(r);
  }

  deque<int> Q;
  bool is_inside[MAXN];
  int par_idx[MAXN], par[MAXN], dist[MAXN];
  bool spfa()
  {
    for(int i = 0; i <= cnt_nodes; i++)
      dist[i] = INF;
    dist[t] = INF;

    Q.clear();
    dist[s] = 0;
    is_inside[s] = true;
    Q.push_back(s);

    while(!Q.empty())
    {
      int u = Q.front();
      is_inside[u] = false;
      Q.pop_front();

      for(int i = 0; i < (int)G[u].size(); i++)
        if(G[u][i].cap > G[u][i].flow && dist[u] + G[u][i].cost < dist[G[u][i].to])
        {
          dist[G[u][i].to] = dist[u] + G[u][i].cost;
          par_idx[G[u][i].to] = i;
          par[G[u][i].to] = u;

          if(is_inside[G[u][i].to]) continue;
          if(!Q.empty() && dist[G[u][i].to] > dist[Q.front()]) Q.push_back(G[u][i].to);
          else Q.push_front(G[u][i].to);

          is_inside[G[u][i].to] = true;
        }
    }

    return dist[t] != INF;
  }

  ii minCostFlow(int flow)
  {
    int f = 0, ret = 0;
    while(f <= flow && spfa())
    {
      int mn_flow = flow - f, u = t;
      while(u != s)
      {
        mn_flow = min(mn_flow, G[par[u]][par_idx[u]].cap - G[par[u]][par_idx[u]].flow);
        u = par[u];
      }

      u = t;
      while(u != s)
      {
        G[par[u]][par_idx[u]].flow += mn_flow;
        G[u][G[par[u]][par_idx[u]].rev].flow -= mn_flow;
        ret += G[par[u]][par_idx[u]].cost * (double)mn_flow;
        u = par[u];
      }

      f += mn_flow;
    }

    return make_pair(f, ret);
  }
};
