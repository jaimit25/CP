#include <bits/stdc++.h>
#define ll long long int
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

void helper(string &s, long long int &num, int i, int &t) {

  // base case
  if (i == s.size())
    return;

  if (s[i] >= '0' && s[i] <= '9') {
    num *= 10;
    num += (int)(s[i] - '0');

  } else
    return;

  if (t != -1 && num > INT_MAX) {
    num = INT_MAX;
    return;
  }
  if (t == -1 && num > INT_MAX) {
    num = -2147483648;
    return;
  }
  helper(s, num, i + 1, t);
}

int myAtoi(string &s) {


   int n = s.size();
   long long int ans = 0;
   int sign = 1; // 1 is positive and -1 is negative

   int i = 0;
   while (i < n && s[i] == ' ')
     i++;

   if (s[i] == '-' || s[i] == '+') {
     if (s[i] == '-')
       sign = -1;
     i++;
   }

     helper(s,ans,i,sign);
     if (ans < INT_MIN){
         return -2147483648;
     }
     if (sign == -1 && ans > INT_MAX){
          return -2147483648;
     }

  return sign*ans;
}

int main() {


  // string s = "   -42";
  string s = "  words are 2";

  long long int ans = myAtoi(s);
  cout << ans << endl;

  return 0;
}
