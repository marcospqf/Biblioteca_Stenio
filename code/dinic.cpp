// grafo bipartido O(Esqrt(v))
// Para recuperar a resposta, e so colocar um bool
// de false na aresta de retorno e fazer uma bfs/dfs
// andando pelos vertices de capacidade =0 e arestas
// que nao sao de retorno

template <class T> struct Edge {
  int v, rev;
  T cap;
  Edge(int v_, T cap_, int rev_) : v(v_), cap(cap_), rev(rev_) {}
};

template <class T> struct Dinic {
  vector<vector<Edge<T>>> g;
  vector<int> level;
  queue<int> q;
  T flow;
  int n;
  Dinic(int n_) : g(n_), level(n_), n(n_) {}
  void AddEdge(int u, int v, T cap) {
    if (u == v)
      return;
    Edge<T> e(v, cap, int(g[v].size()));
    Edge<T> r(u, 0, int(g[u].size()));
    g[u].push_back(e);
    g[v].push_back(r);
  }

  bool BuildLevelGraph(int src, int sink) {
    fill(level.begin(), level.end(), -1);
    while (not q.empty())
      q.pop();
    level[src] = 0;
    q.push(src);
    while (not q.empty()) {
      int u = q.front();
      q.pop();
      for (auto e = g[u].begin(); e != g[u].end(); ++e) {
        if (not e->cap or level[e->v] != -1)
          continue;
        level[e->v] = level[u] + 1;
        if (e->v == sink)
          return true;
        q.push(e->v);
      }
    }
    return false;
  }

  T BlockingFlow(int u, int sink, T f) {
    if (u == sink or not f)
      return f;
    T fu = f;
    for (auto e = g[u].begin(); e != g[u].end(); ++e) {
      if (not e->cap or level[e->v] != level[u] + 1)
        continue;
      T mincap = BlockingFlow(e->v, sink, min(fu, e->cap));
      if (mincap) {
        g[e->v][e->rev].cap += mincap;
        e->cap -= mincap;
        fu -= mincap;
      }
    }
    if (f == fu)
      level[u] = -1;
    return f - fu;
  }

  T MaxFlow(int src, int sink) {
    flow = 0;
    while (BuildLevelGraph(src, sink))
      flow += BlockingFlow(src, sink, numeric_limits<T>::max());
    return flow;
  }
};
