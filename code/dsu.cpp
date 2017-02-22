const int N=500010;
int p[N],Rank[N];
void init()
{
  memset(Rank,0,sizeof(Rank));
  for(int i=0;i<N;i++) p[i]=i;
}
int findset(int i)
{
  if(p[i]==i) return i;
  return p[i]=findset(p[i]);
}
bool same(int i, int j)
{
  return (findset(i) == findset(j));
}
void unionSet(int i, int j)
{
  if (!same(i, j)) {
    int x = findset(i), y=findset(j);
  if (Rank[x] > Rank[y])
      p[y] = x;
    else {
      p[x] = y;
      if (Rank[x] == Rank[y]) Rank[y]++;
    }
  }
}
