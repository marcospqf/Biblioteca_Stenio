//Use: vector<vector<T>> result = MatPow<T>(m1, expoent)
	template<class T>
vector<vector<T>> MatMul(vector<vector<T>> &m1, vector<vector<T>> &m2)
{
	vector<vector<T>> ans;
	ans.resize(m1.size(), vector<T>(m2.size()));
	for (int i = 0; i < m1.size(); i++)
		for (int j = 0; j < m2.size(); j++)
			for (int k = 0; k < m2.size(); k++) {
				ans[i][j] += m1[i][k] * m2[k][j];
				ans[i][j] %= MOD;
			}
	return ans;
}

	template<class T>
vector< vector<T> > MatPow(vector<vector<T>>  &m1, ll p)
{
	vector< vector<T>> ans;
	ans.resize(m1.size(), vector<T>(m1.size()));
	for (int i = 0; i < m1.size(); i++) ans[i][i] = 1;
	while (p>0) {
		if (p %2) ans = MatMul(ans, m1);
		m1 = MatMul(m1, m1);
		p>>=1;
	}
	return ans;
}
// VETOR TEM N LINHAS E A MATRIZ E QUADRADA
	template<class T>
vector<T> MulVet(vector<vector<T>> &m1, vector<T> &vet)
{
	vector<T> ans;
	ans.resize(vet.size());
	for (int i = 0; i < m1.size(); i++)
		for (int j = 0; j < vet.size(); j++) {
			ans[i] += (m1[i][j] * vet[j]);
			ans[i] %= MOD;
		}
	return ans;
}
