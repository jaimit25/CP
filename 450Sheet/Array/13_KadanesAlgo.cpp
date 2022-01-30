#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution
{

public:
	long long maxSubarraySum(int arr[], int n)
	{

		int sum = 0;
		int max = INT32_MIN;

		for (int i = 0; i < n; i++)
		{
			if (sum < 0)
				sum = 0;
				sum = sum + arr[i];

			if(sum > max)
				max = sum;

		}

		return max;
	}
};

int main()
{
	Solution obj ; 
	int n ; 
	cin >> n ;
	int *A = new int[n];
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	cout<<"Max Sub Array sum is : "<<obj.maxSubarraySum(A, n)<<endl;

	return 0;
}