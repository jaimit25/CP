#include <iostream>
using namespace std;

  

void display(int *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{	

	//Brute force include counting number of zero's ones and two's in the Array

	int A[] = {1,2,0,0,2,1,1}, sz = 7;
	display(A, sz);

	//Using Dutch National Flag Algorithm

	int low = 0;
	int hi = sz - 1;
	int mid = 0;


	while (mid <= hi)
	{
		switch (A[mid])
		{
		case 0:
			swap(A[low], A[mid]);
			low++;
			mid++;
			break;

		case 1:
			mid++;
			break;

		case 2:
			swap(A[hi], A[mid]);
			hi--;
			break;
		}
	}

	display(A, sz);

	return 0;
}