#include <bits/stdc++.h>
#include <string>
using namespace std;

bool isValid(string s)
{
  stack<char> temp;
  for (int i = 0; i < s.length(); i++)
  {
    if (temp.empty())
    {
      temp.push(s[i]);
    }
    else if ((temp.top() == '(' && s[i] == ')') || (temp.top() == '{' && s[i] == '}') || (temp.top() == '[' && s[i] == ']'))
    {
      temp.pop();
    }
    else
    {
      temp.push(s[i]);
    }
  }
  if (temp.empty())
  {
    return true;
  }
  return false;
}

int main()
{
  string s = "{}{}";
  bool ans = isValid(s);
  if (ans)
    cout << "True" << endl;
  else
    cout << "False" << endl;
  return 0;
}