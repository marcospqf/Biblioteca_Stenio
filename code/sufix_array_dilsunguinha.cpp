struct SuffixArray{
    const string& s;
    int n;
    vector<int> order, rank, lcp;
    vector<int> count, x, y;
    vector<int> sparse[22];
    SuffixArray(const string& s) : s(s), n(s.size()), order(n), rank(n),
    count(n + 1), x(n), y(n), lcp(n){
        for(int i=0;i<22;i++) sparse[i].resize(n, 0);
        build();
        buildLCP();
    }
    
    void build(){
        //sort suffiixes by the first character
        for(int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b){return s[a] < s[b];});
        rank[order[0]] = 0;
        for(int i = 1; i < n; i++){
            rank[order[i]] = rank[order[i - 1]];
            if(s[order[i]] != s[order[i - 1]]) rank[order[i]]++;
        }
        
        
        //sort suffixex by the the first 2*p characters, for p in 1, 2, 4, 8,...
        for(int p = 1; p < n, rank[order[n - 1]] < n - 1; p <<= 1){
            for(int i = 0; i < n; i++){
                x[i] = rank[i];
                y[i] = i + p < n ? rank[i + p] + 1 : 0;
            }
            
            radixPass(y);
            radixPass(x);
            
            rank[order[0]] = 0;
            for(int i = 1; i < n; i++){
                rank[order[i]] = rank[order[i - 1]];
                if(x[order[i]] != x[order[i - 1]] or y[order[i]] != y[order[i - 1]]) rank[order[i]]++;;
            }
        }
    }
    
    //Stable counting sort
    void radixPass(vector<int>& key){
        fill(count.begin(), count.end(), 0);
        for(auto index : order) count[key[index]]++;
        for(int i = 1; i <= n; i++) count[i] += count[i - 1];
        for(int i = n - 1; i >= 0; i--) lcp[--count[key[order[i]]]] = order[i];
        order.swap(lcp);
    }
    
    //Kasai's algorithm to build the LCP array from order, rank and s
    //For i >= 1, lcp[i] refers to the suffixes starting at order[i] and order[i - 1]
    void buildLCP(){
        lcp[0] = 0;
        int k = 0;
        for(int i = 0; i < n; i++){
            if(rank[i] == n - 1){
                k = 0;
            }else{
                int j = order[rank[i] + 1];
                while(i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
                lcp[rank[j]] = k;
                if(k) k--;
            }
        }
        for(int i=0;i<n;i++) sparse[0][i] = lcp[i];
        for(int j=1;j<22;j++)
            for(int i=n-1;i - (1 << (j-1) ) >=0; i--)
                sparse[j][i] = min(sparse[j-1][i], sparse[j-1][i - (1<< (j-1))]);
    }
    //Calcula o LCP do intervalo i e j.
    int LCP(int i, int j){
        if(i>j) return 0;
        if(i==j) return n-order[j];
        int k = log2(j-i);
        while(j - (1<<k) > i) k++;
        while(j - (1<<k) < i) k--;
        return min(sparse[k][j], sparse[k][i+ (1<<k) ]);
    }
};
 
 
int main(){
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  SuffixArray sa(s);
  for(int i = 0; i < s.size(); i++) cout << sa.order[i] << '\n';
}
