//Retorna os componentes fortemente conectados
//Se o usados[i]=usados[j], temos que i e j 
//pertencem ao mesmo componente, col-1= numero
//de componentes fortemente conectados do grafo
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
  {
    graph[u].pb(v);
    trans[v].pb(u);
  }
  void dfs(int u, int pass, int color)
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
};
