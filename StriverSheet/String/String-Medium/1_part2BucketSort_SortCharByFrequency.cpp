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
#define vi vector<int>

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
    int temp = a[i];
    while (a[j] > temp && j >= 0) {
      a[j + 1] = a[j];
      j--; 
    }
    a[j + 1] = temp;
    i++;
  }
}

vector<int> bucketSort(vi &a) {
  int n = a.size();
  vi ans;
  

  return ans;
}

int main() {
  //   vi a = {2, 1, 0, 2};
  vi a = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
  vi ans = bucketSort(a);
  printv(ans);

  return 0;
}
