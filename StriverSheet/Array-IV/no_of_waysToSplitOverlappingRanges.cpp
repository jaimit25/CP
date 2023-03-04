#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vvll vector<vector<long long>>
#define svi set<vector<int>>
#define si set<int>

using namespace std;

template <class T> void print(T &a) {
  for (auto it : a) {
    cout << it << " ";
  }
  cout << endl;
}

template <class T> void print2(T &a) {
  for (auto it : a) {
    for (auto i : it) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int getMedian(vi &temps) {
  int n = temps.size();
  if (n % 2 == 0) {
    return temps[n / 2] + temps[n / 2 + 1];
  }
  return temps[(n / 2)];
}

int power(int i, int j, int p) {
  if (j == 0) {
    return 1;
  }
  if (j == 1) {
    return i;
  }
  long long  ans = power(i, j / 2, p);
  ans = (ans * ans) % p;
  if (j % 2 == 1) {
    ans = (ans * i) % p;
  }
  return ans;
}
int countWays(vector<vector<int>> &ranges) {
  sort(ranges.begin(), ranges.end());
  vector<vector<int>> ans;
  for (auto &i : ranges) {
    if (ans.size() == 0 or ans.back()[1] < i[0]) {
      ans.push_back(i);
    } else {
      ans.back()[1] = max(ans.back()[1], i[1]);
    }
  }
  int sz = ans.size();
  return power(2, sz, 1e9 + 7);
}

int main() {


  return 0;
}
