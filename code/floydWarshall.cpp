//menor caminho para todos os vertices
for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
    if (graph[i][j] != INF) pai[i][j] = i;

for (int k = 0; k < n; k++) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] > graph[i][k] + graph[k][j]) {
        graph[i][j] = graph[i][k] + graph[k][j];
        pai[i][j] = pai[k][j];
      }
    }
  }
}
