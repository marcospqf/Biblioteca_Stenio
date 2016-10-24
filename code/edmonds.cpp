struct Edge {
  int at, where;
  ll cap;
  void init(int _at, ll _cap, int _where)
  {
    at = _at, cap = _cap, where = _where;
  }
};
struct dad {
  int at, up, down;
  dad() { at = -1; }
  dad(int _at, int _up, int _down) { at = _at, up = _up, down = _down; }
};
class MaxFlow {
 private:
  vector<vector<Edge> > g;
  ll mf, f;
  int s, t;
  vector<dad> p;

 public:
  void augment(int v, ll minEdge)
  {
    if (v == s) {
      f = minEdge;
      return;
    }
    else if (p[v].at != -1) {
      augment(p[v].at, min(minEdge, g[p[v].at][p[v].up].cap));
      g[p[v].at][p[v].up].cap -= f;
      g[v][p[v].down].cap += f;
    }
  }
  void init(int N)
  {
    for (int i = 0; i < g.size(); i++) g[i].clear();
    mf = 0, f = 0;
    g.resize(N);
  }
  void addEdge(int u, int v, ll cap)
  {
    Edge A;
    A.init(v, cap, g[v].size());
    Edge B;
    B.init(u, 0, g[u].size());
    g[u].pb(A);
    g[v].pb(B);
  }
  int maxFlow(int source, int sink)
  {
    s = source;
    t = sink;
    mf = 0;
    while (true) {
      f = 0;
      vector<int> dist(g.size(), INF);
      dist[s] = 0;
      queue<int> q;
      q.push(s);
      p.clear();
      p.resize(g.size());
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) break;
        for (int i = 0; i < g[u].size(); i++) {
          Edge prox = g[u][i];
          if (dist[prox.at] == INF and prox.cap > 0) {
            dist[prox.at] = dist[u] + 1;
            q.push(prox.at);
            dad paizao(u, i, prox.where);
            p[prox.at] = paizao;
          }
        }
      }
      augment(t, INF);
      if (f == 0) break;
      mf += f;
    }
    return mf;
  }
};
