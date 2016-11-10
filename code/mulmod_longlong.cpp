/* Metodo para calcular (a*b) mod m onde a e b são inteiros com 64-bits cada.
Fonte: http://bit.ly/1pp7xEZ */
ll mulmod(ll a, ll b, ll m) {
	ll y = (ll)( (ld)a*(ld)b/m + (ld)1/2 );
	y = y * m;
	ll x = a * b, r = x - y;
	if ((ll) r < 0) { r = r + m; y = y - 1; }
	return r;
}
