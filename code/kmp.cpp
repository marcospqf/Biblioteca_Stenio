int p[N];
int n;
void process(vi &s)
{
    int i = 0, j = -1;
    p[0] = -1;
    while (i < s.size()) {
        while ( j >= 0 and s[i] != s[j] ) j = p[j];
        i++, j++;
        p[i] = j;
    }
}
// s=texto , t= padrao
int match(string &s, string &t)
{
    int ret = 0;
    process(t);
    int i = 0, j = 0;
    while (i < s.size()) {
        while (j >= 0 and  (s[i] != t[j] ) ) j = p[j];
        i++, j++;
        if (j == t.size()) {
            j = p[j];
            ret++;
        }
    }
    return ret;
}
