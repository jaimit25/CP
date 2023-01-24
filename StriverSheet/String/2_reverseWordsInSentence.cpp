#include <bits/stdc++.h>
#include <sstream>

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

void print(vector<string> &s) {
  for (auto it : s) {
    cout << it << endl;
  }
  // cout<<endl;
}

string reverseWords(string &s) {
  string word, ans;
  stringstream stream(s);

  stack<string> st;

  // getting words from the string s using stringbuffer class
  while (stream >> word) {
    st.push(word);
  }

  while (!st.empty()) {
    ans = ans + st.top() + " ";
    st.pop();
  }
  ans.pop_back();

  return ans;
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("output.txt", "w", stdout);
#endif

  string sen = "the sky is blue";
  // string sen = "  hello world  ";
  string ans = reverseWords(sen);
  cout << ans << endl;

  return 0;
}
