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

				/* this is tricky -- see above
				explanation/diagram for merge()*/
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