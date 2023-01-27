#include <algorithm>
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

void printv(vi &a) {
  for (auto it : a)
    cout << it << " ";
  cout << endl;
}

vector<int> bucketSort(vi &a) {
  int n = a.size();
  int max_ele = *max_element(a.begin(), a.end());

  vi c(max_ele + 1, 0);

  // find the frequency
  for (auto it : a)
    c[it]++;

  // cumilative frequency
  for (int i = 1; i <= max_ele; i++)
    c[i] = c[i] + c[i - 1];

  // creating vector b for storing sorted elements
    vi b(n, 0);

  // Iterate in vector a reverse order
  for (int j = n - 1; j >= 0; j--) {
    b[c[a[j]]-1] = a[j];
    c[a[j]]--;
  }

  return b;
}

int main() {
  //  freopen("output.txt", "w", stdout);
  //   vi a = {2, 1, 0, 2};
  vi a = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
  vi ans = bucketSort(a);
  printv(ans);

  return 0;
}
