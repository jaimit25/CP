#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>
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

template <class T> void print(T a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }
  cout << endl;
}

string longestCommonPrefix(vector<string> &str) {
  sort(begin(str), end(str));
  int n = str.size();
  if (n == 0)
    return "";

  string f = str[0];
  string l = str[n - 1];
  string ans = "";

  for (int i = 0; i < f.size(); i++) {
    if (f[i] == l[i])
      ans = ans + f[i];
    else
      break;
  }
  return ans;
}

int main() {
  freopen("output.txt", "w", stdout);

  vector<string> str = {
      "flower",
      "flow"
      "flight",
  };
  cout << longestCommonPrefix(str) << endl;
  return 0;
}