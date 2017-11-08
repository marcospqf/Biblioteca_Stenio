const int N=500010;
int p[N],Rank[N];
void init()
{
	for(int i=0;i<N;i++) p[i]=i, Rank[i]=1;
}
int findSet(int i)
{
	if(p[i]==i) return i;
	return p[i]=findSet(p[i]);
}
bool sameSet(int i, int j)
{
	return (findSet(i) == findSet(j));
}
void unionSet(int i, int j)
{
	if (!sameSet(i, j)) {
		int x = findSet(i), y=findSet(j);
		if (Rank[x] > Rank[y]){
			p[y] = x;
			Rank[x] += Rank[y];
		}
		else {
			p[x] = y;
			Rank[y] += Rank[x];
		}
	}
}
