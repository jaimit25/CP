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

void printVec(vi a)
{
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}

// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     priority_queue<int,vector<int>, greater<int> > mh;
//     for (int i = 0; i < m; i++)
//     {
//         mh.push(nums1[i]);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         mh.push(nums2[i]);
//     }
//     int sz = mh.size();
//     nums1.clear();
//     for (int i =0  ; i <sz;i++)
//     {
//         nums1.push_back(mh.top());
//         mh.pop();
//     }
// }
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int gap = (m + n) ;
    
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        int i = 0, j = 0;
        // loop through
        for (i = 0; i + gap < m; i++)
        {   
            if (nums1[i + gap] < nums1[i])
            {
                swap(nums1[i + gap], nums1[i]);
            }
        }
        for (j = gap > m ? gap - m : 0; i < m && j < n; i++, j++)
        {
            if (nums1[i] > nums2[j])
            {
                swap(nums1[i], nums2[j]);
            }
        }
        if (j < n)
        {
            // we are still not at the end of nums2
            i = 0;
            while (j < n)
            {
                if (nums2[i] > nums2[j])
                {
                    swap(nums2[i], nums2[j]);
                }
                i++;
                j++;
            }

        }
    }

    for(int i = 0 ; i < n ; i++){
        nums1[m+i] = nums2[i];
    }
}

int main()
{
    // type Code
    vi a, b;
    // a = {1, 4, 8, 10,0,0,0};
    // b = {2, 3, 9};
    // merge(a, 4, b, 3);
    //  printVec(a);

    // a = {1};
    // b = {};
    // merge(a, 1, b, 0);
    //  printVec(a);


    a = {2,0};
    b = {1};
    merge(a, 1, b, 1);
    printVec(a);
    return 0;
}
