#include <iostream>
using namespace std;

void print(int A[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

int main()
{

	int A[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	cout << endl;
	int T[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0}};
	print(A);

	int i, j;
	//Printing ...Transpose Matrix is
	cout << "Transpose Matrix is : " << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			T[i][j] = A[j][i];
		}
	}
	print(T);

	cout << "Other method for transpose : " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (j = 0; j <= i; j++)
		{
			swap(T[i][j], T[j][i]);
		}
	}
	print(T);

	return 0;
}