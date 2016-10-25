class kosaraju {
 private:
  vi usados;
  vvi graph;
  vvi trans;
  vi pilha;

 public:
  kosaraju(int N)
  {
    graph.resize(N);
    trans.resize(N);
  }
  void AddEdge(int u, int v)

      graph[u]
          .pb(v);
  trans[v].pb(u);
} void dfs(int u, int pass, int color)
{
  usados[u] = color;
  vi vizinhos;
  if (pass == 1)
    vizinhos = graph[u];
  else
    vizinhos = trans[u];
  for (int j = 0; j < vizinhos.size(); j++) {
    int v = vizinhos[j];
    if (usados[v] == 0) {
      dfs(v, pass, color);
    }
  }
  pilha.pb(u);
}
int SSC(int n)
{
  pilha.clear();
  usados.assign(n, 0);
  for (int i = 0; i < n; i++) {
    if (!usados[i]) dfs(i, 1, 1);
  }
  usados.assign(n, 0);
  int color = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (usados[pilha[i]] == 0) {
      dfs(pilha[i], 2, color);
      color++;
    }
  }
  return color - 1;
}
vvi compression(int n)
{
  int tam = SSC(n);
  vvi resp;
  vvi Trans;
  resp.resize(tam);
  Trans.resize(tam);
  for (int u = 0; u < graph.size(); u++) {
    for (int j = 0; j < graph[u].size(); j++) {
      int v = graph[u][j];
      if (usados[u] != usados[v]) {
        resp[usados[u] - 1].pb(usados[v] - 1);
        Trans[usados[v] - 1].pb(usados[u] - 1);
      }
    }
  }
  return Trans;
}
}
;
