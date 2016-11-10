//Fazer combinacao de N escolhe M 
//por meio do triangulo de pascal
//Complexidade: O(m*n)
unsigned long long comb[61][61];
for (int i = 0; i < 61; i++) {
   comb[i][i] = 1;
   comb[i][0] = 1;
}
for (int i = 2; i < 61; i++)
   for (int j = 1; j < i; j++)
    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
