#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void Print(int vec[], int n, string s)
	{
		for (int i = 0; i < n; i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}

	// int _mergeSort(int arr[], int temp[], int left, int right);
	// int merge(int arr[], int temp[], int left, int mid,
	// 	  int right);

	int mergeSort(long long int arr[], int array_size)
	{
		int temp[array_size];
		return rmergeSort(arr, temp, 0, array_size - 1);
	}

	int rmergeSort(long long int arr[], int temp[], int left, int right)
	{
		int mid, inv_count = 0;
		if (right > left)
		{
			mid = (right + left) / 2;
			inv_count += rmergeSort(arr, temp, left, mid);
			inv_count += rmergeSort(arr, temp, mid + 1, right);
			inv_count += merge(arr, temp, left, mid + 1, right);
		}
		return inv_count;
	}

	/* This funt merges two sorted arrays
	and returns inversion count in the arrays.*/
	int merge(long long int arr[], int temp[], int left, int mid,
		  int right)
	{
		int i, j, k;
		int inv_count = 0;

		i = left; /* i is index for left subarray*/
		j = mid;  /* j is index for right subarray*/
		k = left; /* k is index for resultant merged subarray*/
		while ((i <= mid - 1) && (j <= right))
		{
			if (arr[i] <= arr[j])
			{
				temp[k++] = arr[i++];
			}
			else
			{
				temp[k++] = arr[j++];
				inv_count = inv_count + (mid - i);
			}
		}

		/* Copy the remaining elements of left subarray
	    (if there are any) to temp*/
		while (i <= mid - 1)
			temp[k++] = arr[i++];

		/* Copy the remaining elements of right subarray
		   (if there are any) to temp*/
		while (j <= right)
			temp[k++] = arr[j++];

		/*Copy back the merged elements to original array*/
		for (i = left; i <= right; i++)
			arr[i] = temp[i];

		return inv_count;
	}
	long long int inversionCount(long long arr[], long long N)
	{
		long long int ans = mergeSort(arr, N);
		return ans;
	}
};

int main()
{

	Solution obj;

	return 0;
}





//for left side as (low = low ,  mid = mid) ,right side as (low = mid+1,high = high)  while merging sorted arrays.
// #include <bits/stdc++.h>
// #define F first
// #define S second
// #define pb push_back
// #define si set<int>
// #define vi vector<int>
// #define pii pair<int, int>
// #define vpi vector<pii>
// #define vpp vector<pair<int, pii>>
// #define mii map<int, int>
// #define mpi map<pii, int>
// #define spi set<pii>
// #define vvi vector<vector<int>>

// using namespace std;

// int ml(vi &a, int l, int m, int h) {
//   vi temp;
//   int c = 0;
//   int i = l, j = m + 1;
//   while (i <= m && j <= h) {
//     if (a[i] <= a[j]) {
//       temp.pb(a[i++]);
//     } else {
//       c = c + (m - i + 1);
//       temp.pb(a[j++]);
//     }
//   }
//   for (; i <= m; i++) {
//     temp.pb(a[i]);
//   }
//   for (; j <= h; j++) {
//     temp.pb(a[j]);
//   }
//   i = l;
//   for (auto it : temp) {
//     a[i++] = it;
//   }
//   return c;
// }

// int f(vi &a, int l, int h) {

//   int c = 0;
//   if (l < h) {
//     int mid = (l + h) / 2;
//     c += f(a, l, mid);
//     c += f(a, mid + 1, h);
//     c += ml(a, l, mid, h);
//   }

//   return c;
// }

// void print(vi &a) {
//   for (auto it : a) {
//     cout << it << " ";
//   }
//   cout << endl;
// }

// int main() {

//   freopen("output.txt", "w", stdout);
// //   vi a = {5, 3, 2, 4, 1};
// 	vi a = {8, 4, 2, 1};
//   cout<<f(a, 0, a.size() - 1)<<endl;
//   print(a);

//   return 0;
// }