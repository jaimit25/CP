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

vector<int> twoSum(vector<int> &nums, int target)
{

    vector<int> ans, num = nums;
    int i = 0;
    int j = num.size() - 1;
    sort(num.begin(), num.end());
    int n1, n2;
    while (i < j)
    {
        if (num[i] + num[j] == target)
        {
            cout << "called" << endl;
            n1 = num[i];
            n2 = num[j];
            // ans.push_back(num[i]);
            // ans.push_back(num[j]);
            break;
        }
        else if (num[i] + num[j] > target)
            j--;
        else if (num[i] + num[j] < target)
            i++;
    }
    // we have to return indices
    for (int k = 0; k < nums.size(); k++)
    {
        if (nums[k] == n1)
            ans.push_back(k);
        else if (nums[k] == n2)
            ans.push_back(k);
    }

    return ans;
}

int main()
{
    vi mat = {2, 7, 11, 15};
    mat = twoSum(mat, 9);
    for (auto it : mat)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}