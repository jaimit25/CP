#include <iostream>
using namespace std;

int main()
{

	int key = 31;
	int A[] = {2, 4, 7, 11, 14, 16, 20, 21}, n = 8;
	int i, j;
	int sum = 0;
	i = 0;
	j = n - 1;

	while( i < j)
	{
		if (A[i] + A[j] == key)
		{
			cout << "Key found : " <<A[i] <<" "<<A[j]<<endl;;
			
			break;
		}
		else if (A[i]+A[j] > key)
		{
				j--;
		}
		else{
			i++;
		}

		if (i == j)
		{
			cout << "Key Not Present" << endl;
			break;
		}
	}

	return 0;
}