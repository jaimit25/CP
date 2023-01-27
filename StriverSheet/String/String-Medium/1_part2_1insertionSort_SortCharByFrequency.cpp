//we need insertion sort in bucketsort algorithm
#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

// insertion_sort
void isort(vi &a) {
  int n = a.size();
  int i = 1;

  while (i <= n - 1) {
    int j = i - 1;
    int temp = a[i];

    // the j pointer will point at index whose value is lesser than temp;
    // 2 _ 5 6 ...n-1  (temp = 4)
    // ^         ^
    // |         |
    // j         i
    while (a[j] > temp && j >= 0) {
      a[j + 1] = a[j];
      j--; 
    }
    a[j + 1] = temp;
    i++;
  }
}
void printv(vi &a) {
  for (auto it : a)
    cout << it << " ";
  cout << endl;
}

int main() {

  vi a = {1, 5, 2, 0};
  isort(a);
  printv(a);

  return 0;

  return 0;
}
