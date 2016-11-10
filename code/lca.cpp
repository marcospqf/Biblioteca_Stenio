//antes de usar as queries de lca, e etc..
//certifique-se de chamar a dfs da arvore e
//process()
const int N = 100000;
const int M = 22;
int P[N][M];
int big[N][M], low[N][M], level[N];
vii graph[N];
int n;

void dfs(int u, int last, int l)
{
  level[u] = l;
  P[u][0] = last;
  for (ii v : graph[u])
    if (v.first != last) {
      big[v.first][0] = low[v.first][0] = v.second;
      dfs(v.first, u, l + 1);
    }
}

void process()
{
  for (int j = 1; j < M; j++)
    for (int i = 1; i <= n; i++) {
      P[i][j] = P[P[i][j - 1]][j - 1];
      big[i][j] = max(big[i][j - 1], big[P[i][j - 1]][j - 1]);
      low[i][j] = min(low[i][j - 1], low[P[i][j - 1]][j - 1]);
    }
}

int lca(int u, int v)
{
  if (level[u] < level[v]) swap(u, v);
  for (int i = M - 1; i >= 0; i--)
    if (level[u] - (1 << i) >= level[v]) u = P[u][i];
  if (u == v) return u;
  for (int i = M - 1; i >= 0; i--) {
    if (P[u][i] != P[v][i]) u = P[u][i], v = P[v][i];
  }
  return P[u][0];
}

int maximum(int u, int v, int x)
{
  int resp = 0;
  for (int i = M - 1; i >= 0; i--)
    if (level[u] - (1 << i) >= level[x]) {
      resp = max(resp, big[u][i]);
      u = P[u][i];
    }
  for (int i = M - 1; i >= 0; i--)
    if (level[v] - (1 << i) >= level[x]) {
      resp = max(resp, big[v][i]);
      v = P[v][i];
    }
  return resp;
}

int minimum(int u, int v, int x)
{
  int resp = INF;
  for (int i = M - 1; i >= 0; i--)
    if (level[u] - (1 << i) >= level[x]) {
      resp = min(resp, low[u][i]);
      u = P[u][i];
    }
  for (int i = M - 1; i >= 0; i--)
    if (level[v] - (1 << i) >= level[x]) {
      resp = min(resp, low[v][i]);
      v = P[v][i];
    }
  return resp;
}
