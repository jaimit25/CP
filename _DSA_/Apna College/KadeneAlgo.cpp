#include <iostream>
using namespace std;

int maxSumSubArray(int A[], int n)
{
	int maxSum = 0;
	int currSum = 0;

	for (int i = 0; i < n; i++)
	{
		currSum = currSum + A[i];

		if (currSum > maxSum)
		{
			maxSum = currSum;
		}
		if (currSum < 0)
		{
			currSum = 0;
		}
	}

	return maxSum;
}

int main()
{

	int A[] = {5, -4, -2, 6, -1}, n = 5;

	int max = maxSumSubArray(A, n);
	cout << "Max Sum of SubArray is : " << max << endl;

	return 0;
}
