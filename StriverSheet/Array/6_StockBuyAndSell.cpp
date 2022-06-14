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

void printVec(vi v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}
void printA(int *A, int n = 6)
{
    n = 6;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int maxProfit(vector<int> &prices)
{

    vi profit;
    vi temp;
    int n = prices.size() - 1;
    int max_pf = prices[n];
    for (int i = n; i >= 0; i--){
        if(max_pf < prices[i]) max_pf = prices[i];
        temp.push_back(max(max_pf, prices[i]));
    }
    reverse(temp.begin(), temp.end());

    for(int i= 0 ; i <= n ; i++){
        profit.push_back(temp[i] - prices[i]);
    }

     max_pf = INT_MIN;
    for(auto it : profit)
        max_pf = max(it,max_pf);

    return max_pf;
}

int main()
{
    // type Code
    vi prices = {7, 1, 5, 3, 6, 4};
    printVec(prices);
    cout << maxProfit(prices) << endl;

    return 0;
}