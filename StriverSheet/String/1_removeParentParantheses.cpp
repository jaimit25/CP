// https://leetcode.com/problems/remove-outermost-parentheses/description/
#include <bits/stdc++.h>
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

string f(string &s) {
  string ans;

  int len = s.length();
  int p_s = 0; // parent bracket Start
  int p_e = 0; // paarent bracket End
  int c = 1;

  for (int i = 1; i < len; i++) {
    if (s[i] == '(')
      c++;
    else
      c--;
    if (c == 0) {
      // end of parental bracket
      p_e = i;
      int no_of_chars_in_middle =
          p_e - p_s - 1; // (()) here 2 brackets in middle of parent brackets
      string temp = s.substr(p_s + 1, no_of_chars_in_middle);
      ans.append(temp);
      p_s = i + 1;
    }
  }

  return ans;
}

int main() {

  freopen("output.txt", "w", stdout);

  string s = "(()())(())(()(()))";
  cout << f(s) << endl;
  return 0;
}