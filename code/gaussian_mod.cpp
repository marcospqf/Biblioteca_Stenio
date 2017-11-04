const int N=105;
const int MAXN = 1e6+10;

//resolvendo o sisteminha Ax = B
//fazendo operacoes de mod p
//no final, B tem a solucao x
//det eh o determinante de A
// complexidade: O(n^3)

ll A[N][N], B[N];
ll inv[MAXN];
int n, p;

ll extended_euclid(int i, int p) {

}

ll soma(ll a, ll b) {
	return ((a + b) % p + p) % p;
}
ll sub(ll a, ll b) {
	return ((a - b) % p + p) % p;
}
ll mul(ll a, ll b) {
	return ((a * b) % p + p) % p;
}

void solve() {
	for(int i=1; i<p; i++) {
		inv[i] = extended_euclid(i, p);
	}

	ll mult;
	ll det = 1;

	for(int i=0; i<n; i++) {
		int nx = i;
		while(nx < n and A[nx][i] == 0) nx++;
		if(nx == n) {
			det = 0;
			//NO SOLUTION or INFINITY SOLUTIONS
		}
		if(nx != i) {
			swap(A[nx], A[i]);
			swap(B[nx], B[i]);
			det = -det;
		}

		det = mul(det, A[i][i]);

		// normalizando
		mult = inv[A[i][i]];
		for(int j=0; j<n; j++) {
			A[i][j] = mul(A[i][j], mult);
		}
		B[i] = mul(B[i], mult);

		for(int j=0; j<n; j++) {
			if(j == i) continue;
			if(A[j][i] != 0) {
				mult = A[j][i];
				for(int k=0; k<n; k++) {
					A[j][k] = sub(A[j][k], mul(mult, A[i][k]));
				}
				B[j] = sub(B[j], mul(mult, B[i]));
			}
		}
	}
}
