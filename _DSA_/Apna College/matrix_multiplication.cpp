#include <iostream>
using namespace std;

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

int main()
{

	int A[3][4] = {
	    {2, 4, 1, 2},
	    {8, 4, 3, 6},
	    {1, 7, 9, 5},
	};

	int B[4][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	    {4, 5, 6},
	};

	int i, j;
	int M[4][3];

	cout << "Printing Array 1 : " << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Printing Array 2 : " << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << B[i][j] << " ";
		}
		cout << endl;
	}

	cout<<"Answer Matrix is : "<<endl;
	j = 0;
	int sum = 0;
	int k;
	for(i = 0 ; i < 3 ; i++){
		j = 0;
		while(j < 3){
			k = sum = 0;
			while(k < 4){
				sum = sum + (A[i][k]*B[k][j]);
				k++;	
			}
			M[i][j] = sum;
			j++;
		}

	}
	
	cout << "Printing Answer Array : " << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}