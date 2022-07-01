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

int maxLen(vector<int> &A, int n)
{
    int maxm = 0;
    int sum = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        sum = sum + A[i];
        if (sum == 0)
            maxm = i + 1;
        else
        {
            if (mp.find(sum) != mp.end())
            { // find function will return pointer to that element & mp.end() will point the the next address of the last Index
                // check if the prefix sum previously existed in the hash map or not
                maxm = max(maxm, i - mp[sum]);
            }
            else
            {
                mp[sum] = i; // Will store hashmap<prefixSum,index>;
            }
        }
    }

    return maxm;
}

// we willl hashing to optimize the approach inetad of traversing o(n2) times the whole array and watching all Sub Array
int main()
{
    vi a = {15,-2,2,-8,1,7,10,23};
    cout<<maxLen(a,8)<<endl;
    return 0;
}