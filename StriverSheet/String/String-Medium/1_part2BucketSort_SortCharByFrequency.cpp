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
//  this code is for Bucket sort algorithm

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#define vi vector<float>

using namespace std;

void printv(vi &a) {
  for (auto it : a)
    cout << it << " ";
  cout << endl;
}

// insertion_sort
void isort(vi &a) {
  int n = a.size();
  int i = 1;
  while (i <= n - 1) {
    int j = i - 1;
    float temp = a[i];
    while (a[j] > temp && j >= 0) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
    i++;
  }
}

vector<float> bucketSort(vi &a) {
  int n = a.size();
  vi ans;
  vi b[n];
  for (int i = 0; i < n; i++) {
    int ind = (n * a[i]);
    b[ind].push_back(a[i]);
  }
  for (int i = 0; i < n; i++) {
    // sort(b[i].begin(), b[i].end());
    isort(b[i]);
  }

  for (int i = 0; i < n; i++) {
    for (auto it : b[i]) {
      ans.push_back(it);
    }
  }

  return ans;
}

int main() {
  // this code works only for 0 < a[i] < 1
    vi a = {0.4,0.5,0.2};
  // vi a = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
  vi ans = bucketSort(a);
  printv(ans);

  return 0;
}
