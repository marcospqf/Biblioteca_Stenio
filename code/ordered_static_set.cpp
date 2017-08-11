#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define imprime(v) for(int X=0;X<v.size();X++) printf("%d ", v[X]); printf("\n");
#define endl "\n"
const int INF= 0x3f3f3f3f;
const long double pi= acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vector< int > > vvi;
const int MOD=1e9+7;
const ll LINF=0x3f3f3f3f3f3f3f3f;
///USANDO ORDERED STATIC SET PRA ESTRUTURA

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef struct cu {
	int a;
	int b;
	bool operator < (const struct cu &other) const {
		if(a != other.a) return a < other.a;
		return b < other.b;
	}

	bool operator == (const struct cu &other) const {
		return(a == other.a and b == other.b);
	}

}cuzao;

bool cmp(const cuzao &a, const cuzao &b) {
	return true;
}

typedef tree<
cuzao,
	null_type,
	less<cuzao>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;


int main()
{
	ordered_set os;
	cuzao asd;
	asd.a = 1;
	asd.b = 2;
	os.insert(asd);
	asd.a = 4;
	os.insert(asd);
	cout<<(os.find(asd) == end(os))<<endl;//0
	cout<<os.order_of_key(asd)<<endl;//1
	asd.a = 1;
	cout<<os.order_of_key(asd)<<endl;//0
	cout<<os.find_by_order(0)->a<<" "<<os.find_by_order(0)->b<<endl;//1 2
	cout<<os.find_by_order(1)->a<<" "<<os.find_by_order(1)->b<<endl;//4 2
	return 0;
}




//USANDO ORDERED STATIC SET PRA CONTAINER DO STL MESMO
#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define imprime(v) for(int X=0;X<v.size();X++) printf("%d ", v[X]); printf("\n");
#define endl "\n"
const int INF= 0x3f3f3f3f;
const long double pi= acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vector< int > > vvi;
const int MOD=1e9+7;
const ll LINF=0x3f3f3f3f3f3f3f3f;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<
int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;//n é multi


int main()
{
	ordered_set os;
	os.insert(1);
	os.insert(10);
	os.insert(1);
	os.insert(15);
	cout<<(os.find(10) == end(os))<<endl;//0 mesma coisa q !count
	cout<<os.order_of_key(10)<<endl;//1 qual o indice do valor 10, se n tem o indice, pega o proximo
	cout<<os.order_of_key(2)<<endl;//1
	cout<<*os.upper_bound(2)<<endl;//10
	cout<<*os.find_by_order(0)<<endl;//1
	cout<<*os.find_by_order(2)<<endl;//15
	return 0;
}
