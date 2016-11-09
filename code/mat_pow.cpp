//matmul multiplica m1 por m2
//matpow exponencia a matrix m1 por p
//mul vet multiplica a matrix m1 pelo vetor vet
vvi matmul(vvi &m1, vvi &m2)
{
  vvi ans;
  ans.resize(m1.size(), vi(m2.size(), 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) {
        ans[i][j] += m1[i][k] * m2[k][j];
        ans[i][j] %= MOD;
      }
  return ans;
}
vvi matpow(vvi &m1, ll p)
{
  vvi ans;
  ans.resize(m1.size(), vi(m1.size(), 0));
  for (int i = 0; i < n; i++) ans[i][i] = 1;
  while (p) {
    if (p & 1) ans = matmul(ans, m1);
    m1 = matmul(m1, m1);
    p >>= 1;
  }
  return ans;
}
// VETOR TEM N LINHAS E A MATRIZ E QUADRADA
vi mulvet(vvi &m1, vi &vet)
{
  vi ans;
  ans.resize(vet.size(), 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ans[i] += (m1[i][j] * vet[j]);
      ans[i] %= MOD;
    }
  return ans;
}
