#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  string s;
  stringstream ss;
  while (scanf("%d", &n), n) {
    getchar();                 // removendo o \n
    while (getline(cin, s)) {  // getline pra ler a string toda
      if (s.compare("0") == 0)
        break;  // parar se for 0
      else {
        ss.clear();        // limpando o stringstream
        ss.str(s);         // jogando a string no stringstream
        while (ss >> x) {  // lendo todos os ints do stringstream
          printf("%d ", x);
        }
        printf("\n");
      }
    }
  }
}
