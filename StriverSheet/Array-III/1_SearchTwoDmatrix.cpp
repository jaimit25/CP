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

// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//      int col = matrix.size();
//     int row = matrix[0].size();
//     int i = 0, last_element = matrix[0][col];

//     if(matrix.size() == 1 && matrix[0].size() == 1){
//         if(matrix[0][0] == target) return true;
//         return false;
//     }

//     while (i < col)
//     {
//         if ( target <= last_element )
//         {
//             for (int k = 0; k < matrix[i].size(); k++)
//             {
//                 if (matrix[i][k] == target){
//                     return true;
//                 }
//             }
//             return false;
//         }
//         i++;
//         last_element = matrix[i][col];
//     }
//     return false;
// }

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int lo = 0;
    if (!matrix.size())
        return false;
    int hi = (matrix.size() * matrix[0].size()) - 1;

    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target)
        {
            return true;
        }
        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return false;
}

int main()
{
    vvi matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // vvi matrix = {{1}};
    if (searchMatrix(matrix, 11))
    {
        cout << "Found" << endl;
    }
    else
        cout << "Not Found" << endl;

    return 0;
}