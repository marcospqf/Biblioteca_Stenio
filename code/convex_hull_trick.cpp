/* Esse convex hull trick e para achar a reta minima!
 * Para maximizar a reta dada , basta trocar o '>' para
 * para '<' na funcao query;
 * Nao chamar query com B ou A vazios! Atualizar dp para
 * depois fazer a query =)
 * ATENCAO COM O DOUBLE!! ESTA EM LONG LONG :) 
*/
vi A[N], B[N];
int pont[N];
bool odomeioehlixo(int r1, int r2, int r3, int j)
{
  return (B[j][r1] - B[j][r3]) * (A[j][r2] - A[j][r1]) <
         (B[j][r1] - B[j][r2]) * (A[j][r3] - A[j][r1]);
}

void add(ll a, ll b, int j)
{
  B[j].pb(b);
  A[j].pb(a);
  while (B[j].size() >= 3 and
         odomeioehlixo(B[j].size() - 3, B[j].size() - 2, B[j].size() - 1, j)) {
    B[j].erase(B[j].end() - 2);
    A[j].erase(A[j].end() - 2);
  }
}

ll query(ll x, int j)
{
  if (pont[j] >= B[j].size()) pont[j] = B[j].size() - 1;
  while (pont[j] < B[j].size() - 1 and
         (A[j][pont[j] + 1] * x + B[j][pont[j] + 1] >
          A[j][pont[j]] * x + B[j][pont[j]]))
    pont[j]++;
  return A[j][pont[j]] * x + B[j][pont[j]];
}
/* Testado em :
 * http://www.spoj.com/problems/APIO10A/ 
 * http://www.spoj.com/problems/ACQUIRE/
*/
