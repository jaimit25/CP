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

string longestPalindrome(string s) {
  if (s.empty())
    return "";
  if (s.size() == 1)
    return s;
  int min_start = 0, max_len = 1;
  for (int i = 0; i < s.size();) {
    if (s.size() - i <= max_len / 2)
      break;
    int j = i, k = i;
    while (k < s.size() - 1 && s[k + 1] == s[k])
      ++k; // Skip duplicate characters.
    i = k + 1;
    while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
      ++k;
      --j;
    } // Expand.
    int new_len = k - j + 1;
    if (new_len > max_len) {
      min_start = j;
      max_len = new_len;
    }
  }
  return s.substr(min_start, max_len);
}

int main() {

  freopen("output.txt", "w", stdout);

  return 0;
}