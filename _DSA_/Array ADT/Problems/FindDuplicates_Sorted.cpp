#include <iostream>
using namespace std;

int main()
{
	int j = 0;
	int A[10] = {1, 2, 3, 4, 5, 6, 8, 8, 8, 9};
	for (int i = 0; i < 9; i++)
	{
		if (A[i] == A[i + 1])
		{
			j = i + 1;

			while (A[j] == A[i])
			{

				j++;
				// cout << "j value : " << j << endl;
			}
			cout << "Element " << A[i] << " Repeated : " << j - i << " Times" << endl;

			i = j - 1;
		}
	}

	return 0;
}