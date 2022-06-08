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

int kthSmallest(int arr[], int l, int r, int k)
{
    // priority_queue<int, vector<int>, greater<int> > pq;
    // for (int i = 0; i <= r; i++)
    //     pq.push(arr[i]);
    // for (int i = 1; i < k; i++)
    //     pq.pop();
    // return pq.top();
    priority_queue<int> pq;
    for (int i = 0; i <= r; i++)
        pq.push(-(arr[i]));
    for (auto e: pq)
    {
        cout << " " << e;
    }
    for (int i = 1; i < k; i++)
        pq.pop();

    return -(pq.top());
}

int main()
{
    int a[] = {7, 10, 4, 3, 20, 15};
    int l = 0, r = 6, k = 3;

    cout << kthSmallest(a, l, r, k) << endl;

    return 0;
}