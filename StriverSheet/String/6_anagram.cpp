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

// bool isAnagram(string s, string t) { 
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t; 
//     }


bool isAnagram(string s, string t) {
  int n = s.length();
  int m = t.length();

  if (m != n)
    return false;
  map<char, int> mp;

  for (auto it : s) {
    mp[it]++;
  }
  for (auto it : t) {
    mp[it]--;
  }
  for (auto it : mp) {
    if (it.second != 0)
      return false;
  }

  return true;
}

int main() {

  string s = "abcd";
  string t = "bcad";
  if (isAnagram(s, t)) {
    cout << "true" << endl;
  }

  return 0;
}