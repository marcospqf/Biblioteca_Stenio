bool domeioehlixo(int r1, int r2, int r3, int j)
{
      return (B[j][r1]-B[j][r3])*(A[j][r2]-A[j][r1])<(B[j][r1]-B[j][r2])*(A[j][r3]-A[j][r1]);
}

void add(double a, double b, int j)
{
      B[j].pb(b);
          A[j].pb(a);
              while(B[j].size()>=3 and domeioehlixo(B[j].size()-3,B[j].size()-2,B[j].size()-1,j))
                    {
                              B[j].erase(B[j].end()-2);
                                      A[j].erase(A[j].end()-2);
                                          }
}

double query(double isi,int j)
{
      if(pont[j]>=B[j].size()) pont[j]=B[j].size()-1;
          while(pont[j]<B[j].size()-1 and (A[j][pont[j]+1]*isi + B[j][pont[j]+1] < A[j][pont[j]]*isi + B[j][pont[j]])) pont[j]++;
              return A[j][pont[j]]*isi + B[j][pont[j]];
}

