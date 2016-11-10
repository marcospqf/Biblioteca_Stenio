// FFT - The Iterative Version
// 
// Running Time:
//    O(n*log n)
// 
// How To Use:
//   fft(a,1)
//   fft(b,1)
//   mul(a,b)
//   fft(a,-1)
//  
// INPUT:
//  - fft method:
//      * The vector representing the polynomial
//      * 1 to normal transform
//      * -1 to inverse transform
//  - mul method:
//      * The two polynomials to be multiplyed
//
// OUTPUT:
//  - fft method: Transforms the vector sent.
//  - mul method: The result is kept in the first vector.
//
// NOTES:
//  - You can either use the struct defined of define dificil as complex<double>
// 
// SOLVED:
//  * Codeforces Round #296 (Div. 1) D. Fuzzy Search
//  

struct dificil {
  double real;
  double im;
  dificil() {
    real=0.0;
    im=0.0;
  }

  dificil(double real, double im):real(real),im(im){}

  dificil operator+(const dificil &o)const {
    return dificil(o.real+real, im+o.im);
  }

  dificil operator/(double v) const {
    return dificil(real/v, im/v);
  }

  dificil operator*(const dificil &o)const {
    return dificil(real*o.real-im*o.im, real*o.im+im*o.real);
  }

  dificil operator-(const dificil &o) const {
    return dificil(real-o.real, im-o.im);
  }
};

dificil tmp[MAXN*2];
int coco,maiorpot2[MAXN];

void fft(vector<dificil> &A, int s)
{
  int n = A.size(), p = 0;

  while(n>1){
    p++;
    n >>= 1;
  }

  n = (1<<p);

  vector<dificil> a=A;

  for(int i = 0; i < n; ++i){
    int rev = 0;
    for(int j = 0; j < p; ++j){
      rev <<= 1;
      rev |= ( (i >> j) & 1 );
    }
    A[i] = a[rev];
  }

  dificil w, wn;

  for(int i = 1; i <= p; ++i){
    int M = 1 << i;
    int K = M >> 1;
    wn = dificil(cos(s*2.0*pi/(double)M), sin(s*2.0*pi/(double)M) );
    for(int j = 0; j < n; j += M){
      w = dificil(1.0, 0.0);
      for(int l = j; l < K + j; ++l){
        dificil t = w;
        t = t*A[l + K];
        dificil u = A[l];
        A[l] =A[l]+ t;
        u = u-t;
        A[l + K] = u;
        w = wn*w;
      }
    }
  }

  if(s==-1){
    for(int i = 0;i<n;++i)
      A[i] = A[i]/(double)n;
  }
}

void mul(vector<dificil> &a, vector<dificil> &b)
{
  for(int i=0;i<a.size();i++)
  {
    a[i]=a[i]*b[i];
  }
}
