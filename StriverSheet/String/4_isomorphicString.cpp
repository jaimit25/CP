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

bool f(string s, string t) {
  int n = s.length();
  int m = t.length();

  if (m != n)
    return false;

  map<char, char> mp;
  map<char, bool> m_p;

  for (int i = 0; i < n; i++) {
    if (mp[s[i]]) {
      // map already exist
      if (mp[s[i]] != t[i]) {
        return false;
      }
    } else {
      // the value of t[i] shouldt be there in the map otherwise it is one to
      // many for(s,t)
      if (m_p[t[i]]) {
        return false;
      } else {

	//create a map mp and also create one more map  m_p(to denote ie. a->b , then value "b" is already used);
        mp[s[i]] = t[i];
        m_p[t[i]] = true; // value used
      }
    } 
  }

  return true;
}

int main() {
  freopen("output.txt", "w", stdout);
  string s = "abc";
  string t = "xyz";
  if (f(s, t))
    cout << "isomorphic" << endl;
  else
    cout << "not isomorphic" << endl;

  return 0;
}