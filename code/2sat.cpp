//RODAR O COMPONENTE FORTEMENTE CONECTADO
//RECUPERAR NA ORDEM DE descarga DA PILHA 
//CONFORME O EXEMPLO A SEGUIR
const int N = 510;
vi graph[N], rev[N];
int us[N];
stack<int> pilha;
int resposta[N];
void dfs1(int u)
{
  us[u] = 1;
  for (int v : graph[u])
    if (!us[v]) dfs1(v);
  pilha.push(u);
}
void dfs2(int u, int color)
{
  us[u] = color;
  for (int v : rev[u])
    if (!us[v]) dfs2(v, color);
}
int Sat(int n)
{
  for (int i = 0; i < n; i++)
    if (!us[i]) dfs1(i);
  int color = 1;
  vi r;
  memset(us, 0, sizeof(us));
  while (!pilha.empty()) {
    int topo = pilha.top();
    r.pb(topo);
    pilha.pop();
    if (!us[topo]) dfs2(topo, color++);
  }
  for (int i = 0; i < n; i += 2) {
    if (us[i] == us[i + 1]) return 0;
  }
  memset(resposta, -1, sizeof(resposta));
  for (int i = r.size() - 1; i >= 0; i--) {
    int vert = r[i] / 2;
    int ok = r[i] % 2;
    if (resposta[vert] == -1) resposta[vert] = !ok;
  }
  return 1;
}
inline void add(int u, int v)
{
  graph[u].pb(v);
  rev[v].pb(u);
}
inline int pos(int u) { return 2 * u; }
inline int neg(int u) { return 2 * u + 1; }
