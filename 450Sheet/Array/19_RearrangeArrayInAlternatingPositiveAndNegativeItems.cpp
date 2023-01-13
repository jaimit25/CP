// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
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

using namespace std;

class Solution
{

public:
	// void swap(int *A, int *b)
	// {
	// 	int temp = *A;
	// 	*A = *b;
	// 	*b = temp;
	// }
	// void printArray(int arr[], int n)
	// {
	// 	for (int i = 0; i < n; i++)
	// 		cout << arr[i] << " ";
	// 	cout << endl;
	// }

	// int *reverseA(int *A, int n, int s, int e)
	// {
	// 	int i = 0, j = 0;
	// 	for (int i = s, j = e; i <= j; i++, j--)
	// 	{
	// 		swap(&A[i], &A[j]);
	// 	}
	// 	return A;
	// }

	// int *negativeOneSide(int *A, int n)
	// {
	// 	int i = 0, j = 0;

	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		if (A[j] < 0)
	// 		{
	// 			swap(&A[j], &A[i]);
	// 			i++;
	// 		}
	// 	}
	// 	return A;
	// }

	// void rearrange(int *A, int n)
	// {
	// 	int i = 1, j = 1;
	// 	int neg = 0;

	// 	A = negativeOneSide(A, n);

	// 	// calculate no of negative integers
	// 	for (i = 0; i < n; i++)
	// 		if (A[i] < 0)
	// 			neg++;

	// 	printArray(A, n);
	// 	cout << endl;

		
	// }



	// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
 
void rearrange(int arr[], int n)
{
    int outofplace = -1;
 
    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            if (((arr[index] >= 0) && (arr[outofplace] < 0))
                || ((arr[index] < 0)
                    && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);
 
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
 
        if (outofplace == -1) {
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {
                outofplace = index;
            }
        }
    }
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

};

int main()
{

	Solution obj;

	int sz;
	cin >> sz;

	int *A = new int[sz];
	for (int i = 0; i < sz; i++)
		cin >> A[i];
	cout << endl;

	// obj.printArray(A, sz);
	// // obj.reverseA(A, sz, 1, 3);
	// obj.rearrange(A, sz);
	// obj.printArray(A, sz);
	obj.rearrange(A, sz);

	return 0;
}