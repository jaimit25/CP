#include <iostream>
using namespace std;

int main()
{

	int A[10] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};

	int min = A[0];
	int max = A[0];

	for (int i = 0; i < 10; i++)
	{
		/* code */
		if (A[i] < min)
		{
			min = A[i];
		}
		else if (A[i] > max)
		{
			max = A[i];
		}
	}
	cout<<min<<endl;
	cout<<max<<endl;

	return 0;
}