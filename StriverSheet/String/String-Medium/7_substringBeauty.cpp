#include <bits/stdc++.h>
#include <cstring>
#define vi vector<int>
using namespace std;

int getBeauty(int *map) {
  int mn = INT_MAX;
  int mx = 0;

  for (int i = 0; i < 26; i++) {
    mx = max(mx, map[i]);
    mn = min(mn, map[i] == 0 ? INT_MAX : map[i]); // any min value apart frm 0
  }

  return (mx - mn);
}

int beautySum(string &s) {
  int n = s.size();
  int arr[26];
  // vi arr(26, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    fill(arr, arr+26, 0);
    // fill(arr.begin(), arr.end(), 0);
    for (int j = i; j < n; j++) {
      arr[s[j] - 'a']++;
      ans = ans + getBeauty(arr);
    }
  }
  return ans;
}

int main() {

  string s = "aabcb";
  cout << beautySum(s) << endl;

  return 0;
}
