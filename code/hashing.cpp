//Certificar que os valores da string correspondente se encontrem
//entre 1 - x, x e o valor maximo. B é um menor primo maior que x.
struct Hashing{
    vector<ull> h, eleva;
    ull B;
    const string &s;
    Hashing(const string &s, ull B) : s(s), h(s.size()), eleva(s.size()){
        eleva[0] =1;
        for(int i=1;i<s.size();i++) eleva[i] = eleva[i-1]*B;
        ull hp=0;
        for(int i=0;i<s.size();i++){
            hp = hp*B + s[i];
            h[i] = hp;
        }
    }
    ull getHash(int i, int j){
        if(i==0) return h[j];
        return h[j] - h[i-1]*eleva[j-i+1];
    }
};
