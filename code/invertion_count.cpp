//conta o numero de inversoes de um array
//x e o tamanho do array, v e o array que quero contar
ll inversoes = 0;
void merge_sort(vi &v, int x)
{
  if (x == 1) return;
  int tam_esq = (x + 1) / 2, tam_dir = x / 2;
  int esq[tam_esq], dir[tam_dir];
  for (int i = 0; i < tam_esq; i++) esq[i] = v[i];
  for (int i = 0; i < tam_dir; i++) dir[i] = v[i + tam_esq];
  merge_sort(esq, tam_esq);
  merge_sort(dir, tam_dir);
  int i_esq = 0, i_dir = 0, i = 0;
  while (i_esq < tam_esq or i_dir < tam_dir) {
    if (i_esq == tam_esq) {
      while (i_dir != tam_dir) {
        v[i] = dir[i_dir];
        i_dir++, i++;
      }
    }
    else if (i_dir == tam_dir) {
      while (i_esq != tam_esq) {
        v[i] = esq[i_esq];
        i_esq++, i++;
        inversoes += i_dir;
      }
    }
    else {
      if (esq[i_esq] <= dir[i_dir]) {
        v[i] = esq[i_esq];
        i++, i_esq++;
        inversoes += i_dir;
      }
      else {
        v[i] = dir[i_dir];
        i++, i_dir++;
      }
    }
  }
}
