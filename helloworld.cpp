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

// int kthSmallest(int arr[], int l, int r, int k)
// {
//     // priority_queue<int, vector<int>, greater<int> > pq;
//     // for (int i = 0; i <= r; i++)
//     //     pq.push(arr[i]);
//     // for (int i = 1; i < k; i++)
//     //     pq.pop();
//     // return pq.top();

//     // priority_queue<int> pq;
//     // for (int i = 0; i <= r; i++)
//     //     pq.push(-(arr[i]));

//     // for (int i = 1; i < k; i++)
//     //     pq.pop();

//     // return -(pq.top());

//     // OPTIMIZED BY SPACE COMPLEXITY
//     priority_queue<int> q;
//     for (int i = l; i <= r; i++)
//     {
//         q.push(arr[i]);
//         if (q.size() > k)
//             q.pop();
//     }
//     return q.top();
// }

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print_SubArray_Sum(int *a, int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}

void print_vector(vector<int> vec)
{
    int n = vec.size();

    cout << "[";
    for (auto it : vec)
        cout << it << ",";
    cout << "] ";
    cout << endl;
}

void print_vector_twoD(vector<vector<int> > vec)
{
    cout << endl;
    cout << " Printing vector 2D : " << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

void print_Array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// void rotate(int arr[], int n)
// {
//     printArray(arr,n);
//     int temp = arr[n - 1];
//     for (int j = n - 1; j >= 0; j--)
//     {
//         arr[j] = arr[j - 1];
//     }
//     arr[0] = temp;
//     printArray(arr,n);
// }

// long long maxSubarraySum(int arr[], int n)
// {

//     long long max_sum = LONG_MIN;
//     long long sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (sum < 0)
//         {
//             sum = 0;
//         }
//         sum = sum + arr[i];
//         max_sum = max(sum, max_sum);
//     }
//     return max_sum;
// }

// Input : [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// vector<vector<int> > merge(vector<vector<int> > &intervals)
// {

//     vector<vector<int> > mergedIntervals;
//     int i = 0;
//     if (intervals.size() == 0)
//         return mergedIntervals;

//     sort(intervals.begin(), intervals.end());
//     vector<int> tempInterval = intervals[0];
//     for (auto it : intervals)
//     {

//         if (it[0] <= tempInterval[1])
//         {
//             // it is inside interval
//             tempInterval[1] = max(it[1], tempInterval[1]);
//         }
//         else
//         {
//             mergedIntervals.push_back(tempInterval);
//             tempInterval = it;
//         }
//     }
//     mergedIntervals.push_back(tempInterval);
//     return mergedIntervals;
// }

void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

void negativeElementLeftSide(int arr[], int n)
{
    int j = 0;
    printArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (j != i)
            {
                swap(&arr[i], &arr[j]);
                j++;
            }
        }
    }
    printArray(arr, n);
}
int getMinDiff(int arr[], int n, int k)
{

    sort(arr, arr + n);
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    int ans = largest - smallest;
    int mi, ma;
    for (int i = 0; i < n - 1; i++)
		{
			ma = max(largest, arr[i] + k);
			mi = min(smallest, arr[i + 1] - k);
			if (mi < 0) // if rigth pair element is greater then the diff btwn rigth adn left pair is negative
				{
					continue;
				}
			ans = min(ans, ma - mi);
		}
		return ans;
}

int main()
{
    int a[] = {7, 10, 4, 3, 20, 15};
    int b[] = {1, 2, 3, -2, 5};
    int c[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int A[] = {1, 5, 8, 10};
    int l = 0, r = 6, k = 3, r1 = 5, r2 = 9, r3 = 4;
    int k1 = 2;

    vector<vector<int> > intervals;
    // [[1,3],[2,6],[8,10],[15,18]];
    vector<int> temp;

    temp.push_back(1);
    temp.push_back(3);
    intervals.push_back(temp);
    temp.clear();

    temp.push_back(2);
    temp.push_back(6);
    intervals.push_back(temp);
    temp.clear();

    temp.push_back(8);
    temp.push_back(10);
    intervals.push_back(temp);
    temp.clear();

    temp.push_back(15);
    temp.push_back(18);
    intervals.push_back(temp);

    // cout << kthSmallest(a, l, r, k) << endl;

    // rotate(a, r);

    // cout << maxSubarraySum(b, r1) << endl;

    // print_SubArray_Sum(b, r1);

    // print_vector_twoD(intervals);
    // vector<vector<int> > ans = merge(intervals);
    // print_vector_twoD(ans);

    // negativeElementLeftSide(c, r2);

    cout<<getMinDiff(A, r3, k1)<<endl;

    return 0;
}



