#include <iostream>
using namespace std;

//pair of element equals to k in sorteed array
int main()
{

	int A[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
	int k = 10;
	int i = 0, j = 9;
	while (i < j)
	{
		if (A[i] + A[j] == k)
		{
			cout << A[i] << " + " << A[j] << " = " << k << endl;
			i++;
			j--;
		}
		else if (A[i] + A[j] < k)
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	for (int i = 0, j = 9; i < j;)
	{
		if (A[i] + A[j] == k)
		{
			cout << A[i] << " + " << A[j] << " = " << k << endl;
			i++;
			j--;
		}
		else if (A[i] + A[j] < k)
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	return 0;
}