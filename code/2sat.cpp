/* Supondo que cada vertice u, o seu
 * positivo e 2*u,  e negativo e 2*i+1
 * resposta[i]=0, significa que o positivo de i e resposta
 * resposta[i]=1, significa que o negativo de i e resposta
 * chamar Sat(n) , n e o numero de vertices do grafo
 * contando com os negativos .. na maioria dos problemas
 * chamar 2*n;
 * testado em :http://codeforces.com/contest/781/problem/D
 * */
int resposta[N];
vi graph[N], rev[N];
int us[N];
stack<int> pilha;
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
    memset(us, 0, sizeof(us));
    while (!pilha.empty()) {
        int topo = pilha.top();
        pilha.pop();
        if (!us[topo]) dfs2(topo, color++);
    }
    for (int i = 0; i < n; i += 2) {
        if (us[i] == us[i + 1]) return 0;
        resposta[i / 2] = (us[i] < us[i + 1]);
    }
    return 1;
}
inline void add(int u, int v)
{
    graph[u].pb(v);
    rev[v].pb(u);
}
