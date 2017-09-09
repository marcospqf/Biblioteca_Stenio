int bigrand() { return (rand()<<16)^rand();}
char r[500001];
struct Node{
	int prior , subtr, sujo;
	int val,add;
	Node *l, *r;
	Node () {}
	Node (int c) : add(0), val(c), prior(bigrand()), l(NULL), r(NULL), subtr(1) {}
};
struct Treap{
	Node *root;
	Treap() : root(NULL) {};
	int cnt(Node *t){
		if(t) return t->subtr;
		return 0;
	}
	void upd(Node* &t){
		if(t){
			if(t->sujo){
				swap(t->l, t->r);
				t->sujo=0;
				if(t->l){
					t->l->sujo^=1;
				}
				if(t->r){
					t->r->sujo^=1;
				}
			}
			t->val+=t->add;
			if(t->l){
				t->l->add+=t->add;
			}
			if(t->r){
				t->r->add+=t->add;
			}
			t->add=0;
			t->subtr= cnt(t->l) + cnt(t->r) + 1;
		}
	}
	Node* merge(Node *L, Node *R){
		upd(R);
		upd(L);
		if(!L) return R;
		if(!R) return L;
		if(L-> prior > R->prior){
			L->r = merge(L->r, R);
			upd(L);
			upd(R);
			return L;
		}
		R->l = merge(L,R->l);
		upd(R);
		upd(L);
		return R;
	}
	//<, >= val
	pair<Node*, Node*> split(Node *t, int val, int add){
		if(!t) {
			return mp(nullptr, nullptr);
		}
		upd(t);
		int cur_key= add + cnt(t->l);
		if(cur_key < val){
			auto ret= split(t->r, val , cur_key+1);
			t->r= ret.first;
			upd(t);
			return mp(t, ret.second);
		}
		auto ret= split( t->l, val , add);
		t->l = ret.second;
		upd(t);
		return mp(ret.first, t);
	}

	Node* inverte(Node* &t, int i, int j, int val){
		if(i>j) return t;
		auto tr1= split(t, j+1, 0);
		auto tr2= split(tr1.first, i, 0);

		if(tr2.second){
			tr2.second->sujo^=1;
			tr2.second->add+=val;
		}
		auto x=merge(tr2.first,tr2.second);
		x=merge(x,tr1.second);
		return x;
	}

	void att(Node* &t, int l , int r, int i, int j){
		t= inverte(t,r+1,i-1,-1);
		t=inverte(t,l,j,1);
	}

	void imprime(Node* &t, int add){
		if(t){
			upd(t);
			int cur_key= add + cnt(t->l);
			imprime(t->l, add);
			imprime(t->r, cur_key+1);
			int aux=t->val+t->add;
			aux%=26;
			aux+=26;
			aux%=26;
			r[cur_key]=aux+'a';
		}
	}

	void poe(Node* &t, string &s){
		for(int i=0;i<s.size();i++){
			Node *aux = new Node(s[i]-'a');
			auto tr= split(t, i, 0);
			auto traux= merge(tr.first, aux);
			t= merge(traux, tr.second);
		}
	}

};
int main()
{
	BUFF;
	int X;
	cin>>X;
	while(X--){
		Treap T;
		string s;
		int op;
		cin>>s>>op;
		T.poe(T.root, s);
		//T.imprime(T.root,0);
		//for(int i=0;i<s.size();i++) {
		//	cout<<r[i];
		//	}
		//cout<<endl;
		//assert(T.root!=NULL);
		while(op--){
			int l,r,i,j;
			cin>>l>>r>>i>>j;
			l--,r--,i--,j--;
			T.att(T.root,l,r,i,j);
		}
		T.imprime(T.root,0);
		for(int i=0;i<s.size();i++) cout<<r[i];
		cout<<endl;
	}
	return 0;
}
