#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// 4 5
// 1 3 5 7
// 0 2 6 8 9

class Solution {

public:
  int nextGap(int gap) {
    if (gap <= 1)
      return 0;
    return (gap / 2) + (gap % 2);
  }
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  void merge(int arr1[], int arr2[], int n, int m) {
    int gap = m + n;
    int i = 0, j = 0;
    // this loop will manage the outer condition (Gap)
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
      // this loop will go to last element pointed by j and then it will stop
      // for Array on left Side
      for (i = 0; i + gap < n; i++) {
        if (arr1[i] > arr1[i + gap]) {
          swap(&arr1[i], &arr1[i + gap]);
        } 
      }

      // we cut the the whole array 1 size to calculate which index we want to
      // place index j
      for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++) {
        if (arr1[i] > arr2[j]) {
          swap(&arr1[i], &arr2[j]);
        }
      }
      // now we are left with whole right Array
      if (j < m) {
        for (j = 0; j + gap < m; j++) {
          if (arr2[j] > arr2[j + gap]) {
            swap(&arr2[j], &arr2[j + gap]);
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      arr1[n + i] = arr2[i];
    }
  }

  // void merge(int arr1[], int arr2[], int n, int m)
  // {
  // 	int i, j, gap = n + m;
  // 	for (gap = nextGap(gap);
  // 	     gap > 0; gap = nextGap(gap))
  // 	{
  // 		// comparing elements in the first array.
  // 		for (i = 0; i + gap < n; i++)
  // 		{
  // 			if (arr1[i] > arr1[i + gap])
  // 			{
  // 				swap(&arr1[i], &arr1[i + gap]);
  // 			}
  // 		}

  // 		// comparing elements in both arrays.
  // 		for (j = gap > n ? gap - n : 0;
  // 		     i < n && j < m;
  // 		     i++, j++)
  // 		{
  // 			if (arr1[i] > arr2[j])
  // 			{
  // 				swap(&arr1[i], &arr2[j]);
  // 			}
  // 		}

  // 		if (j < m)
  // 		{
  // 			// comparing elements in the second array.
  // 			for (j = 0; j + gap < m; j++)
  // 			{
  // 				if (arr2[j] > arr2[j + gap])
  // 				{
  // 					swap(&arr2[j], &arr2[j + gap]);
  // 				}
  // 			}
  // 		}
  // 	}
  // }
};

int main() {

  Solution obj;
  int n, m;
  cin >> n >> m;
  int *A = new int[n];
  int *B = new int[m];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> B[i];
  }

  obj.merge(A, B, n, m);
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  for (int i = 0; i < m; i++) {
    cout << B[i] << " ";
  }
  cout << endl;

  return 0;
}