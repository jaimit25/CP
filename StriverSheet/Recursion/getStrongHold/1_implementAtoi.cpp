#include <bits/stdc++.h>
#define ll long long int
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

void chk(string s, int p, int n, long long &ans, int &t) {
  if (p == n)
    return;

  if (s[p] >= '0' && s[p] <= '9') {
    ans *= 10;
    ans += (int)(s[p] - '0');
  } else {
    return;
  }
  if (t != -1 && ans > INT_MAX) {
    ans = INT_MAX;
    return;
  }
  if (t == -1 && ans > INT_MAX) {
    ans = -2147483648;
    return;
  } 
  chk(s, p + 1, n, ans, t);
}

int myAtoi(string s) {
  int p = 0, t = 1;
  while (p < s.size() && s[p] == ' ')
    p++;
  if (s[p] == '-' || s[p] == '+') {
    if (s[p] == '-')
      t = -1;
    p++;
  }
  long long ans = 0;

  chk(s, p, s.size(), ans, t);
  if (ans < INT_MIN)
    return -2147483648;
  if (t == -1 && ans > INT_MAX)
    return -2147483648;
  return t * ans;
}

int main() {


  // string s = "   -42";
  string s = "  words are 2";

  long long int ans = myAtoi(s);
  cout << ans << endl;

  return 0;
}
