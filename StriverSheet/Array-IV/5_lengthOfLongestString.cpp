#include <bits/stdc++.h>
#include <unordered_set>

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

void printSet(unordered_set<char> s)
{
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
}

int lengthOfLongestSubstring(string str)
{
    if(str.length() == 0 ) return 0;
    int maxans = INT_MIN;
    unordered_set<char> set;
    int l = 0;
    for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
    {
        if (set.find(str[r]) != set.end()) // if duplicate element is found
        {   
            printSet(set);

            while (l < r && set.find(str[r]) != set.end())
            {
                set.erase(str[l]);
                l++;
            }
            // printSet(set);
        }
        set.insert(str[r]);
        maxans = max(maxans, r - l + 1);
    }
    return maxans;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}