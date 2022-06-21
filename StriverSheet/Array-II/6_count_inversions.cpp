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

long long getInversions(long long *arr, int n)
{
    if (n == 1 || n == 0)
        return 0;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                ans++;
            }
        }
    }
    return ans;
}

void printA(long long *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// int mergeSortedList(long long *A,int low ,int mid,int high) {
//     // list1 : 0 + mid
//     // list2 : mid + 1 toß
//     int i = 0;
//     int j = mid + 1;
//     int k = low;
//     int count = 0 ;
//     long long  *temp = new long long[high + 1];
//     while (i <= mid && j <= high)
//     {
//         cout<<"called"<<endl;
//         if (A[i] < A[j])
//         {
//             temp[k] = A[i];
//             i++;
//             k++;

//         }
//         if (A[i] > A[j])
//         {
//             temp[k] = A[j];
//             j++;
//             k++;
//             count = count + (mid-i);
//         }
//     }
//     if(i < mid){
//         // i has not reach till middle which means list 2 is done
//         for(int x = i ; x <= mid ; x++,k++) temp[k] = A[x];
//     }
//     else if(j<high){
//         for(int x = j ; x <= high ; x++,k++) temp[k] = A[x];
//     }
//     for(int i = low ; i <= high ; i++){
//         A[i] = temp[i];
//     }
//     return count;
// }
// int recursiveMergeSort(long long A[], int l, int h)
// {
//      int mid,inv_count = 0;
// 	if (l < h)
// 	{
// 		mid = (l + h) / 2;
// 		inv_count += recursiveMergeSort(A, l, mid);
// 		inv_count += recursiveMergeSort(A, mid + 1, h);
// 		inv_count += mergeSortedList(A, l, mid, h);
// 	}
//     return inv_count;
// }

int mergeList(long long *A, int l, int m, int h)
{
    long long *temp = new long long[h + 1];
    int i = l, j = m + 1;
    int k = 0;
    int count = 0;
    while (i <= m && j <= h)
    {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
        {
            temp[k++] = A[j++];
            count = count + m - i;
        }
    }
    while (i <= l)
        temp[k++] = A[i++];
    while (j <= h)
        temp[k++] = A[j++];
    for (int i = 0, x = l; i < h + 1 && x <= h; i++, x++)
    {
        A[x] = temp[i];
        cout<<A[x]<<" ";
    }
    cout<<endl;
    return count;
}

int mergeSort(long long *A, int l, int h)
{
    int inv_count = 0;
    if (l < h)
    {
        int mid = (l + h) / 2;
        cout<<mid<<endl;
        //   cout<<"low value is : "<<l<< " mid value is : "<<mid<< " high value is : "<<h<<endl;
        inv_count = inv_count + mergeSort(A, l, mid);
        inv_count = inv_count + mergeSort(A, mid + 1, h);
        //    cout<<"Merging list"<<endl;
        inv_count = inv_count + mergeList(A, l, mid, h);
    }
    return inv_count;
}

int main()
{

    // long long A[] = {5,6,7,1,2};
    // printA(A,5);
    // int low = 0;
    // int mid = 2;
    // int high = 4;
    // int ans = mergeSortedList(A,low,mid,high);
    // printA(A,5);
    // cout<<"ans : "<<ans<<endl;

    // long long arr[] = {1,3,7,0};
    long long arr[] = {2, 5, 1, 3, 4};
    // long long arr[] = {1};
    // long long ans = getInversions(arr, 5);
    // long long ans = getInversions(arr, 3);
    printA(arr, 5);
    int ans = mergeSort(arr, 0, 4);
    printA(arr, 5);
    cout << ans << endl;

    return 0;
}