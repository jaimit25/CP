#include <iostream>
using namespace std;

//find min index repeating element in the g
int main()
{

	int A[] = {-1, 1, 5, 3, 4, 3, 5, 6}, n = 8;
	int B[7] = {0};

	for (int i = 1; i < n; i++)
	{
		B[A[i]]++;
	}

	for (int i = 0; i < 7; i++)
	{
		if (B[i] > 1)
		{
			cout << "Minimum Index is  : " << i << endl;
			break;
		}
	}

	return 0;
}