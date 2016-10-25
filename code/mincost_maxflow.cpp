
int flow[N][N];
vector<pair<int, int> > g[N];

int n, m, k;

inline int ent(int a) { return a * 2; }
inline int out(int a) { return a * 2 + 1; }
inline void addEdge(int a, int b, int custo, int fluxo)
{
  flow[a][b] += fluxo;
  g[a].push_back(make_pair(b, custo));
  g[b].push_back(make_pair(a, -custo));
}

int src = N - 1, tgt = N - 2;
int dis[N], pai[N];

inline int dij()
{
  memset(dis, INF, sizeof dis);
  memset(pai, -1, sizeof pai);
  priority_queue<pair<int, int> > q;
  dis[src] = 0;
  q.push(make_pair(0, src));
  while (!q.empty()) {
    pair<int, int> foo = q.top();
    q.pop();
    int x = foo.second, cost = -foo.first;
    if (dis[x] != cost) continue;
    for (int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].first, w = g[x][i].second;
      if (flow[x][y] <= 0) continue;
      if (dis[y] > dis[x] + w) {
        dis[y] = dis[x] + w;
        pai[y] = x;
        q.push(make_pair(-dis[y], y));
      }
    }
  }
  return dis[tgt] != INF;
}

int minCost()
{
  int maxFlow = 0;
  int minC = 0;
  while (dij()) {
    int u = tgt;
    int minFlow = INF;
    while (pai[u] != -1) {
      minFlow = min(minFlow, flow[pai[u]][u]);
      u = pai[u];
    }
    maxFlow += minFlow;
    minC += minFlow * dis[tgt];
    u = tgt;
    while (pai[u] != -1) {
      flow[pai[u]][u] -= minFlow;
      flow[u][pai[u]] += minFlow;
      u = pai[u];
    }
  }
  if (maxFlow != n * k) minC = -1;
  return minC;
}

inline void init()
{
  memset(flow, 0, sizeof flow);
  for (int i = 0; i < N; ++i) {
    g[i].clear();
  }
}
