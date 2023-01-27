// Given a string s, sort it in decreasing order based on the frequency of the characters.
// The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
//Example
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


//Optimized approach 
// - using bucket sort (similar to count sort algorithm)

#include <algorithm>
#include <bits/stdc++.h>
#define vi vector<int>

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
    b[c[a[j]] - 1] = a[j];
    c[a[j]]--;
  }

  return b;
}

int main() {
  //   vi a = {2, 1, 0, 2};
  vi a = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
  vi ans = bucketSort(a);
  printv(ans);

  return 0;
}
