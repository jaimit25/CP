#include <iostream>
using namespace std;

int main()
{

	char A[] = "painter";
	char B[] = "painter";

	int i, j;
	for (i = 0, j = 0; A[i] != '\0' && B[i] != '\0'; i++, j++)
	{
		if (A[i] == B[j])
		{
			cout << "Index " << i << " same" << endl;
		}
		if (A[i] != B[j])
		{
			cout << "Not Same" << endl;
			if (A[i] < B[j])
			{
				cout << "A comes first in Dictionary" << endl;
			}
			else{
				cout << "B comes first in dictionary" << endl;
			}
			break;
		}
	}

	return 0;
}