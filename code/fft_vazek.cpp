// FFT - The Recursive Version
// 
// Running Time:
//    O(n*log n)
// 
// How To Use:
//   fft(&a[0], tam, 0)
//   fft(&b[0], tam, 0)
//   mul(a,b)
//   fft(&a[0], tam, 1)
//   
// INPUT:
//  - fft method:
//      * The vector representing the polynomial
//      * 0 to normal transform
//      * 1 to inverse transform
//  - mul method:
//      * The two polynomials to be multiplyed
//
// OUTPUT:
//  - fft method: Transforms the vector sent.
//  - mul method: The result is kept in the first vector.
// 
// NOTES:
//  - Tam has to be a power of 2.
//  - You can either use the struct defined of define dificil as complex<double>
//
// SOLVED:
//  * Codeforces Round #296 (Div. 1) D. Fuzzy Search
//  

dificil tmp[MAXN*2];
int coco, maiorpot2[MAXN];

void fft(dificil *v, int N, bool inv)
{
  if(N<=1) return;
  dificil *vodd = v;
  dificil *veven = v+N/2;
  for(int i=0; i<N; i++) tmp[i] = v[i];
  coco = 0;
  for(int i=0; i<N; i+=2)
  {
    veven[coco] = tmp[i];
    vodd[coco] = tmp[i+1];
    coco++;
  }
  fft(&vodd[0], N/2, inv);
  fft(&veven[0], N/2, inv);

  dificil w(1);
  double angucomleite = 2.0*PI/(double)N;
  if(inv) angucomleite = -angucomleite;

  dificil wn(cos(angucomleite),sin(angucomleite));
  for(int i=0;i<N/2;i++)
  {
    tmp[i] = veven[i]+w*vodd[i];
    tmp[i+N/2] = veven[i]-w*vodd[i];
    w *= wn;
    if(inv)
    {
      tmp[i] /= 2;
      tmp[i+N/2] /= 2;
    }
  }
  for(int i=0; i<N; i++) v[i] = tmp[i];
}

void mul(vector<dificil> &a, vector<dificil> &b)
{
  for(int i=0; i<a.size(); i++)
  {
    a[i] = a[i]*b[i];
  }
}

void precomp()
{
  int pot=0;
  for(int i=1;i<MAXN;i++)
  {
    if((1<<pot)<i) pot++;
    maiorpot2[i] = (1<<pot);
  }
}
