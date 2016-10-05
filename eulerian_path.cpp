multiset<int> graph[N];
stack<int> path;

//  It suffices to call dfs1 just
// one time leaving from node 0.
// O(n * log(n))
void dfs1(int u)
{
  while(graph[u].size())
  {
    int v = *graph[u].begin();
    graph[u].erase(graph[u].begin());
    graph[v].erase(graph[v].find(u));
    dfs1(v);
  }
  path.push(u);
}
