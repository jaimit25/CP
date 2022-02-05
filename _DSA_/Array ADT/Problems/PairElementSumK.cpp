#include <iostream>
using namespace std;
int main()
{

	int A[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
	//searching for 11
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; i++)
		{
			if (A[i] + A[j] == 11)
			{
				cout<<A[i]<<" + "<<A[j]<<" = "<< 11<<endl;
				
			}
		}
	}

	return 0;
}