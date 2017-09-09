int bigrand() { return (rand()<<16)^rand();}
struct Node{
	int  prior, val, sum, subtr, pref, suf, maximo;
	Node *l, *r;
	Node () {}
	Node (int x) : maximo(x) , val(x), prior(bigrand()), sum(x), subtr(1) , l(NULL), r(NULL), pref(x), suf(x){}
};
struct Treap{
	Node *root;
	Treap() : root(NULL) {};

	int cnt(Node *t) {
		if(t) return t->subtr;
		return 0;
	}
	int key(Node *t){
		if(t) return t->val;
		return 0;
	}
	int sum(Node *t) {
		if(t) return t->sum;
		return 0;
	}
	int pref(Node *t){
		if(t) return t->pref;
		return -INF;
	}
	int suf(Node *t){
		if(t) return t->suf;
		return -INF;
	}
	int maximo(Node *t){
		if(t) return t->maximo;
		return -INF;
	}

	void upd(Node* &t){
		if(t){
			if(!(t->l)){
				t->pref= max(t->val, t->val + pref(t->r));
			}
			else{
				t->pref= max( pref(t->l), max( sum(t->l) + t->val, sum(t->l) + t->val + pref(t->r)));
			}
			if(!(t->r)){
				t->suf= max(t->val, t->val + suf(t->l));
			}
			else{
				t->suf= max( suf(t->r), max( sum(t->r) + t->val, sum(t->r) + t->val + suf(t->l)));
			}
			t->maximo= max( suf(t->l) + t->val, suf(t->l) +t->val + pref(t->r));
			t->maximo = max(t->maximo , pref(t->r) + t->val);
			t->maximo = max(t->maximo, max( maximo(t->l), maximo(t->r)));
			t->maximo= max(t->maximo, t->val);
			t->sum= sum(t->r)  + sum(t->l) + t->val;
			t->subtr=cnt(t->l) + cnt(t->r) +1 ;
		}
	}
// junta todos menores que val e todos maiores ou iguais a val
	Node* merge(Node* L, Node *R){
		if(!L) return R;
		if(!R) return L;
		if(L->prior > R->prior){
			L->r = merge(L->r, R);
			upd(L);
			return L;
		}
		R->l = merge(L, R->l);
		upd(R);
		return R;
	}
// separa t em todos menores que val , todos maiores ou igual a val
	pair<Node*, Node*> split(Node* t, int val, int add){
		if(!t){
			return mp(nullptr, nullptr);
		}
		int cur_key= add+ cnt(t->l);
		if(cur_key < val){
			auto ret= split(t->r, val, cur_key+1);
			t->r= ret.first;
			upd(t);
			return mp(t, ret.second);
		}
		auto ret= split(t->l, val , add);
		t->l = ret.second;
		upd(t);
		return mp(ret.first, t);
	}

	int querymax(Node *&t, int i, int j){
		auto tr1= split(t, j+1, 0);
		auto tr2= split(tr1.first, i, 0);


		int prefi= pref(tr2.second->r);
		int sufi= suf(tr2.second->l);
		int val= key(tr2.second);

		int r=maximo(tr2.second);	
		auto x= merge(tr2.first, tr2.second);
		t= merge(x, tr1.second);
		return r;
	}

	void insert(Node* &t, int x, int y){
		Node *aux= new Node(y);
		auto tr= split(t, x,0);
		auto traux=merge(tr.first,aux);
		t=merge(traux,tr.second);
	}

	void replace(Node *&t, int x, int y){
		Node *aux= new Node(y);
		erase(t, x);
		auto tr=split(t, x, 0);
		t=merge(tr.first,aux);
		//db(pref(t));
		//db(suf(t));
		t=merge(t, tr.second);
		//	db(pref(t));
		//	db(suf(t));

	}

	void erase(Node * &t, int x){
		auto tr=split(t,x+1,0);
		auto tr2=split(tr.first, x,0);
		t= merge(tr2.first, tr.second);
	}
};
int main()
{
	int n;
	sc(n);
	Treap T;
	for(int i=0;i<n;i++){
		int x;
		sc(x);
		T.insert(T.root, i, x);
	}
	int q;
	sc(q);
	while(q--){
		//db(T.cnt(T.root));
		char op;
		cin>>op;
		if(op=='I'){
			int x,y;
			sc2(x,y);
			x--;
			T.insert(T.root, x, y);
		}
		else if(op=='Q'){
			int l,r;
			sc2(l,r);
			l--,r--;
			pri(T.querymax(T.root, l,r));
		}
		else if(op=='R'){
			int x,y;
			sc2(x,y);
			x--;
			T.replace(T.root, x, y);
		}
		else{
			int x;
			sc(x);
			x--;
			T.erase(T.root, x);
		}
	}
	return 0;
}

