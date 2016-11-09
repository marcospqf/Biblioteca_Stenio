class ponte {
 private:
  vvi graph;
  vi usados;
  vi e_articulacao;
  vi dfs_low;
  vi dfs_prof;
  vector<ii> pontes;
  int tempo;

 public:
  ponte(int N)
  {
    graph.clear();
    graph.resize(N);
    usados.assign(N, 0);
    dfs_low.assign(N, 0);
    dfs_prof.assign(N, 0);
    e_articulacao.assign(N, 0);
    tempo = 0;
  }
  void AddEdge(int u, int v)
  {
    graph[u].pb(v);
    graph[v].pb(u);
  }
  void dfs(int u, int pai)
  {
    usados[u] = 1;
    int nf = 0;
    dfs_low[u] = dfs_prof[u] = tempo++;
    for (int v : graph[u]) {
      if (!usados[v]) {
        dfs(v, u);
        nf++;
        if (dfs_low[v] >= dfs_prof[u] and pai != -1) e_articulacao[u] = true;
        if (pai == -1 and nf > 1) e_articulacao[u] = true;
        if (dfs_low[v] > dfs_prof[u]) pontes.pb(mp(u, v));
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      }
      else if (v != pai)
        dfs_low[u] = min(dfs_low[u], dfs_prof[v]);
    }
  }
  void olha_as_pontes()
  {
    for (int i = 0; i < graph.size(); i++)
      if (!usados[i]) dfs(i, -1);
    if (pontes.size() == 0)
      cout << " Que merda! nao tem ponte!" << endl;
    else {
      for (ii i : pontes) cout << i.first << " " << i.second << endl;
    }
  }
  void olha_as_art()
  {
    for (int i = 0; i < graph.size(); i++)
      if (!usados[i]) dfs(i, -1);
    for (int i = 0; i < e_articulacao.size(); i++)
      if (e_articulacao[i]) cout << " OIAAA A PONTE " << i << endl;
  }
}
