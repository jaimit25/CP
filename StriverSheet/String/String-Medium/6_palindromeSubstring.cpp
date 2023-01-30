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

string longestPalindrome(string &s) {

  int n = s.length();
  if (n == 0)
    return " ";

  string ans = "";
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int l, r;

    // odd length
    l = r = i;
    while (l >= 0 && r < n && s[l] == s[r]) {
      if (r - l + 1 > mx) {
        // if we find new substring with longest length | the previous longest
        // length is stored in the mx variable
        mx = r - l + 1;
        ans = s.substr(l, r - l + 1);
      }
      l--;
      r++;
    }

    // Even length
    l = i;
    r = i + 1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      if (r - l + 1 > mx) {
        mx = r - l + 1;
        ans = s.substr(l, r - l + 1);
      }
      l--;
      r++;
    }
  }
  return ans;
}

int main() {

  string s = "babad";
  cout << longestPalindrome(s) << endl;
  ;

  return 0;
}
