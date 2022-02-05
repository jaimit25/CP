// cond1 :  element should be greater then all its previous elements.
// condn2 : element should be greater then its following element.

#include <iostream>
using namespace std;

int main()
{
	int A[] = {1, 2, 0, 7, 2, 0, 2, 9 ,3 }, n = 8;

	int max = -12;
	int cal = 0;
	int i = 0;
	while (i < n)
	{
		//looping through all elements
		//updating element if its greater then previous max
		if (A[i] > max)
		{
			max = A[i];
		}

		if ((max <= A[i] && A[i] > A[i + 1]) || (max < A[i]) && (i == n - 1))
		{
			cal++;
		}
		i++;
	}

	cout << "No of Record breaking Days : " << cal << endl;
	cout << "Maximum element is : " << max << endl;

	return 0;
}