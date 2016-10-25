int b[100000];
int sizet, sizep;
void kmpPreprocess(string &text, string &pattern)
{
  int i = 0, j = -1;
  b[0] = -1;
  while (i < sizep) {
    while (j >= 0 and pattern[i] != pattern[j]) j = b[j];
    i++, j++;
    b[i] = j;
  }
}

void kmpSearch(string &text, string &pattern)
{
  kmpPreprocess(text, pattern);
  int i = 0, j = 0;
  while (i < sizet) {
    while (j >= 0 and text[i] != pattern[j]) j = b[j];
    i++, j++;
    if (j == sizep) {
      cout << "Olha a substring do texto " << i - j << endl;
      j = b[j];
    }
  }
}
