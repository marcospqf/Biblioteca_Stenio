///USANDO ORDERED STATIC SET PRA ESTRUTURA
//aqui vai o template
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



//aqui vai o template
//USANDO ORDERED STATIC SET PRA CONTAINER DO STL MESMO
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
