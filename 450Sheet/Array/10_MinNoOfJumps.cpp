#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {

public:
  int minJumps(int *arr, int n) {

    if (arr[0] == 0 && n > 1)
      return -1;
    if (n == 1)
      return 0;
    int far = 0;
    int jmp = 0;
    int curr = 0;

    for (int i = 0; i < n - 1; i++) {
      curr = max(curr, arr[i] + i);
      if (far == i) {
        far = curr;
        jmp++;
      }
    }

    if (far < n - 1)
      return -1;

    return jmp;

    // if (n <= 1)
    // 	return 0;

    // if (arr[0] == 0)
    // 	return -1;

    // int reachable = arr[0];
    // int step = arr[0];
    // int jump = 1;

    // for (int i = 1; i < n; i++)
    // {
    // 	if( i == n-1)
    // 		return jump; // returning minimum number of jumps

    // 	reachable = max(reachable , arr[i] + i);
    // 	step--;
    // 	if(step == 0){
    // 		jump++;
    // 		if (i > reachable)
    // 		return -1;
    // 		step = reachable - i;
    // 	}
    // }

    // return -1;
  }
};

int main() {

  Solution obj;

  int n;
  cin >> n;
  int A[n];

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  cout << obj.minJumps(A, n) << endl;

  return 0;
}