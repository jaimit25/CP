#include <iostream>
using namespace std;
int main()
{

	char A[] = "finding";
	int i, j;
	for (i = 0; A[i] != '\0'; i++)
	{
		if (A[i] != -1)
		{
			for (j = i + 1; A[j] != '\0'; j++)
			{
				if (A[j] == A[i])
				{	
					cout<<"Element "<<A[i]<<" Found  Repeating at index  : "<< j<<endl;
					A[j] = -1;
				}
			}
		}
	}

	return 0;
}