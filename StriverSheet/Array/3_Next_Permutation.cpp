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

void printA(vector<int> a)
{
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}

void reverseE(vector<int> arr, int s, int e)
{
    int i, j;
    for (i = s, j = e; i <= j; i++, j--)
        swap(arr[i], arr[j]);
}

void nextPermutation(vector<int> &nums)
{
    int i1;
    int i2;
    for (i1 = nums.size() - 1; i1 >= 0; i1--)
    {
        if (nums[i1 - 1] < nums[i1])
          {
              i1 = i1 - 1;
              break;
          }
    }
    for(i2 = nums.size(); i2>= 0 ; i2--){
        if(nums[i2] > nums[i1]){
          break;
        }
    }

    if (i1 == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    swap(nums[i1],nums[i2]);
    reverse(nums.begin()+1 + i1 ,nums.end());
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(4);
    a.push_back();
   nextPermutation(a);
    printA(a);
    
    return 0;
}