// Given a string s, sort it in decreasing order based on the frequency of the
// characters. The frequency of a character is the number of times it appears in
// the string. Return the sorted string. If there are multiple answers, return
// any of them.
// Example
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
// answer.

// Optimized approach
//  - using bucket sort (similar to count sort algorithm)

#include <algorithm>
#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

string frequencySort(string s) {
  map<char, int> m;
  for (auto c : s) {
    m[c]++;
  }
  vector<pair<int, char>> v;
  for (auto it : m)
    v.push_back({it.second, it.first});
  sort(v.rbegin(), v.rend());

  string ans = "";
  for (auto it : v) {
    for (int i = 0; i < it.first; i++) {
      ans += it.second;
    }
  }
  return ans;
}

int main() {
  string s = "tree";
  string ans = frequencySort(s);
  cout << ans << endl;

  return 0;
}
