//Um exemplo de Divide and conquer:
int MOD = 1e9 + 7;
const int N = 1010;
int dp[N][N], cost[N][N], v[N], pref[N], n, m;
void compDP(int j, int L, int R, int b, int e)
{
  if (L > R) return;
  int mid = (L + R) / 2;
  int idx = -1;
  for (int i = b; i <= min(mid, e); i++)
    if (dp[mid][j] > dp[i][j - 1] + cost[i + 1][mid]) {
      idx = i;
      dp[mid][j] = dp[i][j - 1] + cost[i + 1][mid];
    }
  compDP(j, L, mid - 1, b, idx);
  compDP(j, mid + 1, R, idx, e);
}
//chamada!
for(int i=1;i<=n;i++) dp[i][0]=cost[1][i];
for(int i=1;i<=m;i++) compDP(i,1,n,1,n);
