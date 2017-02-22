/* O(v^3)
* Matching maximo de grafo bipartido de peso 1 nas arestas
* supondo que o grafo bipartido seja enumerado de 0-n-1
* chamamos maxMatch(n)
*/
class MaxMatch {
  vi graph[N];
  int match[N], us[N];

 public:
  MaxMatch(){};
  void addEdge(int u, int v) { graph[u].pb(v); }
  int dfs(int u)
  {
    if (us[u]) return 0;
    us[u] = 1;
    for (int v : graph[u]) {
      if (match[v] == -1 or (dfs(match[v]))) {
        match[v] = u;
        return 1;
      }
    }
    return 0;
  }
  int maxMatch(int n)
  {
    memset(match, -1, sizeof(match));
    int ret = 0;
    for (int i = 0; i < n; i++) {
      memset(us, 0, sizeof(us));
      ret += dfs(i);
    }
    return ret;
  }
};
