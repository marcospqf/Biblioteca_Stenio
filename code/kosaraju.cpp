vii graph[N], rev[N];
int us[N];
stack<int> pilha;
int n, m;
void dfs1(int u)
{
    us[u] = 1;
    for (ii v : graph[u])
        if (!us[v.first]) dfs1(v.first);
    pilha.push(u);
}
void dfs2(int u, int color)
{
    us[u] = color;
    for (ii v : rev[u])
        if (!us[v.first]) dfs2(v.first, color);
}
int Kos(int b)
{
    for (int i = 1; i <= n; i++)
        if (!us[i]) dfs1(i);
    int color = 1;
    memset(us, 0, sizeof(us));
    while (!pilha.empty()) {
        int topo = pilha.top();
        pilha.pop();
        if (!us[topo]) dfs2(topo, color++);
    }
    return color;
}
inline void add(int u, int v, int w)
{
    graph[u].pb(mp(v, w));
    rev[v].pb(mp(u, w));
}
