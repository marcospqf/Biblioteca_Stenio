//asw -> vetor com resposta!!
//asw.size() é o tamanho da maior lis
void lis( const vector< int > & v, vector< int > & asw ) 
{
  vector<int> pd(v.size(),0), pd_index(v.size()), pred(v.size());
  int maxi = 0, x=0, j=0, ind=0;
  for(int i=0;i<v.size();i++) 
  {
    x = v[i];
    j=lower_bound(pd.begin(),pd.begin()+maxi,x) -pd.begin();
    pd[j] = x; 
    pd_index[j] = i;
   if(j==maxi) 
   {
     maxi++; 
     ind = i; 
   }
   if(pred[i] == j) pd_index[j-1] = -1;  
  }
  int pos=maxi-1,k=v[ind];
  asw.resize( maxi );
  while ( pos >= 0 ) 
  {
    asw[pos--] = k;
    ind = pred[ind];
    k = v[ind];
  }
}

