double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  ll x, y; 
  PT() {}
  PT(ll x, ll y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
};

ll dist2(PT p, PT q)   { return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); }

int n;
PT pts[100005];
int id[100005];

bool cmpx(const int &a, const int &b) {
  return pts[a].x < pts[b].x;
}

bool cmpy(const int &a, const int &b) {
  return pts[a].y < pts[b].y;
}

pair<ll, ii> getStrip(vi &strip, ll dmax) {
  sort(strip.begin(), strip.end(), cmpy);
  pair<ll, ii> ret = mp(LINF, mp(-1, -1));
  int id1, id2;
  ll delta;
  for(int i = 0; i < strip.size(); i++) {
    id1 = strip[i];
    for(int j = i + 1; j < strip.size(); j++) {
      id2 = strip[j];
      delta = pts[id1].y - pts[id2].y;
      if(delta * delta > dmax) break;
      ret = min(ret, mp(dist2(pts[id1], pts[id2]), mp(id1, id2)));
    }
  }
  return ret;
}

pair<ll, ii> solve(int b, int e) {
  if(b >= e) return mp(LINF, mp(-1, -1));
  int mid = (b + e) / 2;
  ll xsplit = pts[id[mid]].x;
  pair<ll, ii> p1 = solve(b, mid), p2 = solve(mid + 1, e);
  pair<ll, ii> ret = min(p1, p2);
  ll dmax = ret.first;
  vi strip;
  ll delta;
  for(int i = mid; i <= e; i++) {
    int idx = id[i];
    delta = pts[idx].x - xsplit;
    if(delta * delta > dmax) break;
    strip.pb(idx);
  }
  for(int i = mid - 1; i >= b; i--) {
    int idx = id[i];
    delta = xsplit - pts[idx].x;
    if(delta * delta > dmax) break;
    strip.pb(idx);
  }
  pair<ll, ii> aux = getStrip(strip, dmax);
  return min(aux, ret);
}

int main() {
  BUFF;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
    id[i] = i;
  }
  sort(id, id + n, cmpx);
  pair<ll, ii> ans = solve(0, n - 1);
  if(ans.second.first > ans.second.second) swap(ans.second.first, ans.second.second);
  cout << setprecision(6) << fixed;
  cout << ans.second.first << " " << ans.second.second << " " << sqrt(ans.first) << endl;
  return 0;
}
