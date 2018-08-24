const int N=500010;
int p[N],Rank[N];
void Init()
{
	for(int i=0;i<N;i++) p[i]=i, Rank[i]=1;
}
int FindSet(int i)
{
	if(p[i]==i) return i;
	return p[i]=FindSet(p[i]);
}
bool SameSet(int i, int j)
{
	return (FindSet(i) == FindSet(j));
}
void UnionSet(int i, int j)
{
	if (!SameSet(i, j)) {
		int x = FindSet(i), y=FindSet(j);
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
