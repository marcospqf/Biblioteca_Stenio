const int MOD=1e9+7;
const ll LINF=0x3f3f3f3f3f3f3f3f;
double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

PT RotateCW90(PT p)    { return PT(p.y,-p.x); }

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

PT ComputeCircleCenter(PT a, PT b, PT c) {
  b=(a+b)/2;
  c=(a+c)/2;
  return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

struct circle {
  PT cen;
  double r;
  circle() {}
  circle(PT cen, double r) : cen(cen), r(r) {}
};

bool inside(circle &c, PT &p) {
  return (c.r * c.r + 1e-6 > dist2(p, c.cen));
}

PT bestOf3(PT a, PT b, PT c) {
  if(dot(b - a, c - a) < 1e-9) return (b + c) / 2.0;
  if(dot(a - b, c - b) < 1e-9) return (a + c) / 2.0;
  if(dot(a - c, b - c) < 1e-9) return (a + b) / 2.0;
  return ComputeCircleCenter(a, b, c);
}

circle minCirc(vector<PT> v) {
  int n = v.size();
  random_shuffle(v.begin(), v.end());
  PT p = PT(0.0, 0.0);
  circle ret = circle(p, 0.0);
  for(int i = 0; i < n; i++) {
    if(!inside(ret, v[i])) {
      ret = circle(v[i], 0);
      for(int j = 0; j < i; j++) {
        if(!inside(ret, v[j])) {
          ret = circle((v[i] + v[j]) / 2.0, sqrt(dist2(v[i], v[j])) / 2.0);
          for(int k = 0; k < j; k++) {
            if(!inside(ret, v[k])) {
              p = bestOf3(v[i], v[j], v[k]);
              ret = circle(p, sqrt(dist2(p, v[i])));
            }
          }
        }
      }
    }
  }
  return ret;
}

int main() {
  int n;
  srand(time(NULL));
  BUFF;
  vector<PT> v;
  cin>>n;
  for(int i = 0; i < n; i++) {
    PT p;
    cin>>p.x>>p.y;
    v.pb(p);
  }
  circle c = minCirc(v);
  cout<<setprecision(6)<<fixed;
  cout<<c.cen.x<<" "<<c.cen.y<<" "<<c.r<<endl;
  return 0;
}
