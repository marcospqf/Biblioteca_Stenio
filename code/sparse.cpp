//comutar RMQ , favor inicializar: dp[i][0]=v[0] 
//sendo v[0] o vetor do rmq
//chamar o build!
int dp[200100][22];
int n;
int d[200100];
void build()
{
  d[0] = d[1] = 0;
  for (int i = 2; i < n; i++) d[i] = d[i >> 1] + 1;
  for (int j = 1; j < 22; j++) {
    for (int i = 0; i + (1 << (j - 1)) < n; i++) {
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int query(int i, int j)
{
  int k = d[j - i];
  int x = min(dp[i][k], dp[j - (1 << k) + 1][k]);
  return x;
}
