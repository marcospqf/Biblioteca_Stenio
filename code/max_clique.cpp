int n,k;
ll g[41];
ll dp[(1<<20)];
ll dp2[(1<<20)];
int t1,t2;
//graph is a bitmask
//meet in the middle technique
// complexity : O(sqrt(2)^n)
ll Adam_Sendler()
{
	t1=n/2;
	t2=n-t1;
	ll r=0;
	for(ll mask=1;mask<(1ll<<t1);mask++){
		for(ll j=0;j<t1;j++)
			if(mask&(1ll<<j)) {
				ll outra= mask-(1ll<<j);
				ll r1= __builtin_popcountll(dp[mask]);
				ll r2= __builtin_popcountll(dp[outra]);
				if(r2>r1) dp[mask] = dp[outra];
			}
		bool click=true;
		for(ll j=0;j<t1;j++)
			if( (1ll<<j)&mask)
				if( ((g[j]^mask)&mask)) click=false;
		if(click) dp[mask]=mask;
		ll r1= __builtin_popcountll(dp[mask]);
		r=max(r,r1);
	}

	for(ll mask=1;mask<(1ll<<t2);mask++){
		for(ll j=0;j<t2;j++)
			if(mask&(1ll<<j)) {
				ll outra= mask-(1ll<<j);
				ll r1= __builtin_popcountll(dp2[mask]);
				ll r2= __builtin_popcountll(dp2[outra]);
				if(r2>r1) dp2[mask] = dp2[outra];
			}
		bool click=true;
		for(ll j=0;j<t2;j++){
			if( (1ll<<j)&mask){
				ll m1= g[j+t1];
				ll cara= mask<<t1;
				if((m1^cara)&cara){
					click=false;
				}
			}
		}
		if(click) {
			dp2[mask]=mask;
		}
		ll r1= __builtin_popcountll(dp2[mask]);
		if(r1==0) db(mask);
		r=max(r,r1);	
	}

	for(ll mask=0;mask<(1ll<<t1);mask++){
		ll tudo= (1ll<<n) -1;
		for(ll j=0;j<t1;j++)
			if( (1ll<<j)&mask) tudo&=g[j];

		tudo>>=t1;
		ll x=__builtin_popcountll(dp[mask]);
		ll y=__builtin_popcountll(dp2[tudo]);
		r=max(r, x+y);
	}
	return r;
}

int main()
{
	sc2(n,k);
	for(int i=0;i<n;i++){
		g[i]|=(1ll<<i);
		for(int j=0;j<n;j++){
			int x;
			sc(x);
			if(x){
				g[i]|=(1ll<<j);
			}
		}
	}
	int m=Adam_Sendler();
	//db(m);
	cout<<fixed<<setprecision(10);
	cout<<(k*k*(m-1))/(2.0*m)<<endl;
	return 0;
}
