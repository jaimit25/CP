// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

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

//  In daily share trading, a buyer buys shares in the morning and sells
//  them on the same day. If the trader is allowed to make at most 2
//  in a day, whereas the second transaction can only start after the
// first one is complete (Buy->sell->Buy->sell). Given stock prices
// throughout the day, find out the maximum profit that a share trader
// could have made.

// Input:   price[] = {10, 22, 5, 75, 65, 80}
// Output:  87
// Trader earns 87 as sum of 12, 75
// Buy at 10, sell at 22,
// Buy at 5 and sell at 80

using namespace std;

class Solution
{

public:
  //  Simple Approach
  int maxtwobuysell(int arr[], int size)
  {
    int first_buy = INT_MIN;
    int first_sell = 0;
    int second_buy = INT_MIN;
    int second_sell = 0;

    for (int i = 0; i < size; i++)
    {

      first_buy = max(first_buy, -arr[i]);
      first_sell = max(first_sell, first_buy + arr[i]);
      second_buy = max(second_buy, first_sell - arr[i]);
      second_sell = max(second_sell, second_buy + arr[i]);
    }

    return second_sell;
  }

  // Approach using dp
  int maxtwobuysellDP(int arr[], int n)
  {
    int max_price = arr[n - 1];
    int min_price = arr[0];

    int *dp = new int[n];
    for (int i = 0; i < n; i++)
      dp[i] = 0;

    //  B -> S =>  B -> S
    // there we would be two traversal and we will do 2nd traversal first

    // TRAVERSAL 1
    for (int i = n - 2; i >= 0; i--)
    {
      max_price = max(max_price, arr[i]);
      dp[i] = max(max_price - arr[i], dp[i + 1]);
    }

    // TRAVERSAL 2
    for (int i = 1; i < n; i++)
    {
      min_price = min(min_price, arr[i]);
      dp[i] = max((arr[i] - min_price) + dp[i], dp[i - 1]);
    }

    return dp[n - 1];
  }
};

int main()
{

  Solution obj;

  int sz;
  cin >> sz;

  int *arr = new int[sz];
  for (int i = 0; i < sz; i++)
  {
    cin >> arr[i];
  }

  cout << obj.maxtwobuysellDP(arr, sz) << endl;

  return 0;
}