// use: call process of kmp!
// erase all occurences of t in s
// example:
// s = XAABBB  t = AB
// return s =X

string recursive_match(string s, string t) {
  vector<pair<char, int>> state;
  int v = 0;
  for (char c : s) {
    if (state.size() == 0)
      v = 0;
    else
      v = state.back().second;
    while (v >= 0 and c != t[v])
      v = p[v];
    v++;
    state.pb({c, v});
    if (v == t.size()) {
      while (v > 0) {
        assert(state.size() > 0);
        state.pop_back();
        v--;
      }
    }
  }
  string ret;
  for (auto x : state)
    ret.pb(x.first);
  return ret;
}
