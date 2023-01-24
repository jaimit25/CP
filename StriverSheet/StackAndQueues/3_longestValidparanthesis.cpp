#include <bits/stdc++.h>
#define ll long long int
#define push_back pb
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define vvi vector<vector<int>>

using namespace std;

int longestValidParentheses(string s) {
  int n = s.length(), longest = 0;
  stack<int> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      st.push(i);
    else {
      if (!st.empty()) {
        if (s[st.top()] == '(')
          st.pop();
        else
          st.push(i);
      } else
        st.push(i);
    }
  }
  if (st.empty())
    longest = n;
  else {
    int a = n, b = 0;
    while (!st.empty()) {
      b = st.top();
      st.pop();
      longest = max(longest, a - b - 1);
      a = b;
    }
    longest = max(longest, a);
  }
  return longest;
}

int main() { return 0; }