#include <iostream>
#include<climits>

using namespace std;

int main() 
{
	int A[] = {-1, 4, 7, 2}, n = 4;
	int st = 0, en = 0;
	int l = 0;
	int sum = 0;

	int max = INT32_MIN;


	//brute-force Approach
	for (int i = 0; i < n; i++)
	{
		st = en = i;

		while (en <= n)
		{
			l = st;
			sum = 0;
			while (l != en)
			{
				cout << A[l] <<" ";
				sum = sum + A[l];
				l++;
			}

			cout << endl;
			en++;
			if (max < sum)
			{
				max = sum;
			}

		}
	}

	cout << "Maximum Sum in Sub Array is :  " << max << endl;


	//cumilative sum Approach method... 



	return 0;
}