// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

using namespace std;

class Solution
{

public:
  double findMedianSortedArray(vector<int> &num1, vector<int> &num2)
  {

    if (num2.size() < num1.size())
      return findMedianSortedArray(num2, num1);

    int n1 = num1.size();
    int n2 = num2.size();

    int low = 0;
    int high = n1;

    while (low <= high)
    {
      // int cut1 = (low + high) >> 1;

      // cut 1 and cut 2 is not the index number of "middle element" but instead the number of elements in the left side or array's in left partition. - refer notes. or keerti maam video
      int cut1 = (low + high) / 2; //here high is the number of element in in num1 array. but when using high as " n - size of num1" insted of n-1 then afterwards we have to take (mid-1) instead of just mid.
      int cut2 = (n1+n2 + 1) / 2 - cut1; // (no of element on left side of partition - no of elements selected in num2)

      int left1 = cut1 == 0 ? INT32_MIN : num1[cut1 - 1];
      int left2 = cut2 == 0 ? INT32_MIN : num2[cut2 - 1];

      int right1 = cut1 == n1 ? INT32_MAX : num1[cut1];
      int right2 = cut2 == n2 ? INT32_MAX : num2[cut2];

      if (left1 <= right2 && left2 <= right1)
      {
        if ((n1 + n2) % 2 == 0)
          return (max(left1, left2) + min(right1, right2)) / 2.0;
        else
          return max(left1, left2);
      }
      else if (left1 > right2)
      {
        high = cut1 - 1;
      }
      else
      {
        low = cut1 + 1;
      }
    }

    return 0.0;
  }
};

int main()
{

  Solution obj;
  vector<int> v;

  int sz;
  cin >> sz;
  int temp;

  return 0;
}