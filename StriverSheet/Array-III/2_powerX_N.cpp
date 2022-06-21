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
#define length 10

// double myPow(double x, int n)
// {
//     double ans = 1;
//     int i = 0;

//     if (n == 0)
//         return 1;

//     if (n < 0)
//     {
//         // 1/x^n
//         for (i = 0; i < abs(n); i++)
//         {
//             ans = ans * x;
//         }
//     }
//     else
//     {
//         // x^n
//         for (i = 0; i < n; i++)
//         {
//             ans = ans * x;
//         }
//     }
//     return n >= 0 ? (ans) : (1 / ans);
// }

// Time Exceeded
//  double myPoww(double x, int n)
//  {
//      double ans = 1;
//      int i = 0;
//      double temp = 1;
//      bool flag;
//      int N;
//      flag = n < 0 ? true : false;
//      n = abs(n);
//      if (n == 0)
//          return 1;
//      if (n % 2 == 0)
//      {
//          // 1/x^n - (n*n)^n/2 for even numbers
//          temp = x * x;
//          N = n / 2;
//      }
//      else
//      {
//          // 1/x^n - for odd numbers n = (n-1)   (x*x)^n/2 * x;
//          temp = x * x;
//          N = n - 1;
//          N = N / 2;
//      }
//      cout<<"N value is :" <<N<<endl;
//      while (N)
//      {
//          ans = ans * temp;
//          N--;
//      }
//      ans = n % 2 == 0 ? (ans) : (ans * x);
//      return flag ? (1.00 / ans) : (ans);
//  }

double myPow(double x, int n)
{
    long long nn = (long long)n;
    if (nn < 0)
        nn = -1 * nn;
    double ans = 1.0;
     int count = 0;

    while (nn)
    {
        if (nn % 2 == 1)
        {
            cout<<" n value is : "<<nn<<endl;
            // odd
            ans = ans * x;
            nn = nn - 1;
            count++;
        }
        else
        {
            cout<<" n value is : "<<nn<<endl;
            // even
            x = x * x;
            nn = nn / 2;
            count++;
        }
    }
    cout<<"Count value is : "<<count<<endl;
    return n < 0 ? (1.00 / ans) : ans;
}

int main()
{
    // cout << myPow(1.00000, -2147483648) << endl;
    int x , n;
    cin>>x>>n;
    // cout << myPoww(x, n) << endl;
    cout << (double)myPow(x, n) << endl;
    return 0;
}