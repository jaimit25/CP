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

int longestConsecutive(vector<int> &nums)
{
        int i = 0;
        int prev = nums[i];
        int n = nums.size();
        set<int> s;
        int longestStreak = 0;

        for (i = 0; i < n; i++)
                s.insert(nums[i]);

        for (i = 0; i < n; i++)
        {
                if (!s.count(nums[i] - 1))
                {
                        int currentNum = nums[i];
                        int currentStreak = 1;

                        while (s.count(currentNum + 1))
                        {
                                currentNum += 1; // update the current num to thte next num
                                currentStreak++;
                        }

                        longestStreak = max(longestStreak, currentStreak);
                }
        }
        return longestStreak;
}

int main()
{
        // type Code
        vi v = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        cout << longestConsecutive(v) << endl;

        return 0;
}