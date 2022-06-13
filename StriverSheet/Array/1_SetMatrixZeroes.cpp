#include <bits/stdc++.h>
using namespace std;
#define length 10
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

void print_vvi(vvi v)
{
    for (auto it : v)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void print_vi(vi v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}
void print_a(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void setZeroes(vvi &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    int a_r[length] = {0};
    int a_c[length] = {0};

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                // i : row , j : Column
                a_r[i] = 1;
                a_c[j] = 1;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // i : row, c : column
            if (a_r[i] == 1 || a_c[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vvi matrix;
    matrix.push_back({0, 1, 2, 0});
    matrix.push_back({3, 4, 5, 2});
    matrix.push_back({1, 3, 1, 5});
    print_vvi(matrix);
    setZeroes(matrix);
    print_vvi(matrix);

    return 0;
}
