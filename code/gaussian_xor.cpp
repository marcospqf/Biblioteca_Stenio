#include <bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define f first
#define s second
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

const int N=105;

//esse eh BABA!
//ateh o mp aguenta
//sisteminha Ax = B de xor, B guarda solucao

int A[N][N], B[N];
int n;

void solve() {
	int det = 1;

	for(int i=0; i<n; i++) {
		int nx = i;
		while(nx < n and A[nx][i] == 0) nx++;
		if(nx == n) {
			//NO SOLUTION or MULTIPLE SOLUTIONS
		}
		if(nx != i) {
			swap(A[nx], A[i]);
			swap(B[nx], B[i]);
		}

		for(int j=0; j<n; j++) {
			if(j == i) continue;
			if(A[j][i] != 0) {
				for(int k=0; k<n; k++) {
					A[j][k] ^= A[i][k];
				}
				B[j] ^= B[i];
			}
		}
	}
}

int main() {
	return 0;
}
