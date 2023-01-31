// A parentheses string is valid if and only if:
// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.
// Input: s = "())"
// Output: 1

#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

int minAddToMakeValid(string s) {
  stack<char> st;
  int n = s.size();
  if (n == 0)
    return 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == ')' and !st.empty() and st.top() == '(') {
      st.pop();
    } else
      st.push(s[i]);
  }

  return st.size();
}

int main() {

  string s = "()))((";
  int ans = minAddToMakeValid(s);
  cout << ans << endl;

  return 0;
}
