/* String s to be splitted and the delimiter used to split it. */
vector<string> splitstr(string s, string delimiter)
{
  vector<string> result;
  string str = s, token;
  size_t pos=0;
  while((pos=str.find(delimiter)) != std::string::npos)
  {
    token = str.substr(0, pos);
    result.push_back(token);
    str.erase(0, pos + delimiter.length());
  }
  result.push_back(str);
  return result;
}
