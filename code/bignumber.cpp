void zero_esq(string &resp)
{
  string retorno = resp;
  reverse(retorno.begin(), retorno.end());
  int i = resp.size() - 1;
  while (retorno[i] == '0' and i > 0) {
    retorno.erase(i);
    i--;
  }
  reverse(retorno.begin(), retorno.end());
  resp = retorno;
}
string sum_big(string a, string b)
{
  string resp;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if (a.size() <= b.size()) {
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
      int x = b[i] - '0' + a[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    for (int i = a.size(); i < b.size(); i++) {
      int x = b[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    if (carry > 0) resp.push_back((char)(carry + '0'));
  }
  else {
    int carry = 0;
    for (int i = 0; i < b.size(); i++) {
      int x = a[i] - '0' + b[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    for (int i = b.size(); i < a.size(); i++) {
      int x = a[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    if (carry > 0) resp.push_back((char)(carry + '0'));
  }
  reverse(resp.begin(), resp.end());
  zero_esq(resp);
  return resp;
}
string mul_big(string a, string b)
{
  string resp;
  resp.push_back('0');
  string temp;
  int carry = 0;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < a.size(); i++) {
    temp.clear();
    for (int k = 0; k < i; k++) temp.push_back('0');
    int x = a[i] - '0';
    for (int j = 0; j < b.size(); j++) {
      int y = b[j] - '0';
      int novo = (x * y + carry);
      temp.push_back((novo % 10) + '0');
      carry = novo / 10;
    }
    if (carry > 0) temp.push_back(carry + '0');
    reverse(temp.begin(), temp.end());
    carry = 0;
    resp = sum_big(temp, resp);
  }
  zero_esq(resp);
  return resp;
}
