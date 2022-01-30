#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
	int minJumps(int *arr, int n)
	{
		if (n <= 1)
			return 0;

		if (arr[0] == 0)
			return -1;

		int reachable = arr[0];
		int step = arr[0];
		int jump = 1;


		for (int i = 1; i < n; i++)
		{
			if( i == n-1)
				return jump; //last index

			reachable = max(reachable , arr[i] + i);	


			step--;
			if(step == 0){
				jump++;
				if (i > reachable)
				return -1;
				step = reachable - i;
			}


			// if (i > reachable)
			// 	return -1;
			// i + arr[i]  - it will calculate the new highest index we can reach
			// if (i + arr[i] > reachable)
			// {
			// 	reachable = i + arr[i];

			// 	// we will not increase count value if "i + arr[i]" is greater then array max index
			// 	if ((i + arr[i]) < (n - 1))
			// 		jump++;
			// }
			// reachable = max(reachable, i + arr[i]);
		}

		return -1;

		// return (jump);
	}
};

int main()
{

	Solution obj;

	int n;
	cin >> n;
	int A[n];

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cout << obj.minJumps(A, n) << endl;

	return 0;
}