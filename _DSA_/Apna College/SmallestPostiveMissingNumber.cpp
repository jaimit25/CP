#include <iostream>
using namespace std;

int main()
{

	int A[] = {0, -9, 1, 3, -4, 5}, n = 6;
	int check[5] = {0};

	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (A[i] >= 0)
		{
			check[A[i]]++;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (check[i] == 0)
		{
			//smallest missing number
			cout << "Smallest missing Number is : " << i << endl;
			break;
		}
	}

	return 0;
}