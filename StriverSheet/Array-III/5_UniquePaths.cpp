#include <bits/stdc++.h>
using namespace std;
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
#define length 1000

// In interview global variable we cannot use

// SOLUTION USING DP ARRAY AS STATIC
//   class Solution
//   {
//   public:
//       static int DP[1000][1000];
//       int noOFPaths(int i, int j, int m, int n)
//       {
//           if (DP[i][j] != 0)
//           {
//               return DP[i][j];
//           }

//         if (i == (m - 1) && j == (n - 1))
//         {
//             DP[i][j] = 1;
//             return 1;
//         }
//         if (i >= m || j >= n)
//         {
//             DP[i][j] = 0;
//             return 0;
//         }
//         else
//         {
//             DP[i][j] = noOFPaths(i + 1, j, m, n) + noOFPaths(i, j + 1, m, n);
//             return noOFPaths(i + 1, j, m, n) + noOFPaths(i, j + 1, m, n);
//         }
//     }

//     int uniquePaths(int m, int n)
//     {
//         return noOFPaths(0, 0, m, n);
//     }
// };
//  int Solution::DP[1000][1000] = {{}};

// SOLUTION BY PASSING DP ARRAY AS PARAMETER REFERENCE
//  class Solution
//  {
//  public:
//      // we will use Paramter DP as reference parameter so we will carry same address
//      int noOFPaths(int i, int j, int m, int n, vector<vector<int> > &DP)
//      {
//          if (i == (m - 1) && j == (n - 1))
//              return 1;
//          if (i >= m || j >= n)
//              return 0;
//          if (DP[i][j] != -1)
//          {
//              return DP[i][j];
//          }
//          else // we will store calculated value is DP table as well also DP table is pass by reference so it wont be created again and again
//              return DP[i][j] = noOFPaths(i + 1, j, m, n, DP) + noOFPaths(i, j + 1, m, n, DP);
//      }
//      int uniquePaths(int m, int n)
//      {
//          vector<vector<int> > DP(m, vector<int>(n, -1));
//          return noOFPaths(0, 0, m, n, DP);
//      }
//  };

// SOLUTION USING COMBINOTRICS
class Solution
{
public:
    int getfac(int n)
    {
        int fac = 1;
        for (int i = n; i >= 1; i--)
        {
            fac = fac * i;
        }
        return fac;
    }

    int getCombination(int n, int r)
    {
        // cout<<"numerator is : "<<getfac(n)<<" Denominator is "<<"getfac(r)*getfac(n - r)"<<getfac(r)<<"*"<<getfac(abs(n - r))<<endl;
        return (getfac(n) / (getfac(r) * (getfac(abs(n - r)))));
    }
    int uniquePaths(int m, int n)
    {
        // nCr
        // return getCombination(m+n-2,m-1);
        return getCombination(m + n - 2, n - 1);

        // or
        // int N = n + m - 2;
        //     int r = m - 1;
        //     double res = 1;

        //     for (int i = 1; i <= r; i++)
        //         res = res * (N - r + i) / i;
        //     return (int)res;
    }
};

int main()
{
    //  0,0   0,1
    //  1,0   1,1
    // from 0,0  we have to find number of ways to go there
    // here m = 2 and n = 2 (m: no of rows and n: n of columns)
    Solution obj;

    int ans = obj.uniquePaths(3, 7);
    cout << "Ans is  : " << ans << endl;

    return 0;
}