#include <bits/stdc++.h>
#define ll long long int
#define push_back pb
#define F first
#define S second
using namespace std;

// Recursive Memoization approach
//  int helper(int n,  vector<int> &m){
//  if (n == 0)
//      return 0;
//    if (n == 1)
//      return 1;
//    if (n == 2)
//      return 2;

//   if(m[n] != -1) return m[n];

//   return helper(n - 1,m) + helper(n - 2,m);
// }
// int climbStairs(int n) {
//   vector<int> m(n+1,-1);
//   return helper(n,m);
// }



//Tabulation without space
int climbStairs(int n) {
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  int prev = 2;
  int prev2 = 1;
  int ways = 0;
  for (int i = 2; i < n; i++) {
    ways = prev + prev2;
    prev2 = prev;
    prev = ways;
  }
  return ways;
}

int32_t main() {

  int n = 5;
  cout << climbStairs(n) << endl;

  return 0;
}
