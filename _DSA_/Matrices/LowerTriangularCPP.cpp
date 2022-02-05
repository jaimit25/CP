#include <iostream>
#include <stdlib.h>
using namespace std;

class Matrix
{
private:
	//we take pointer because we dont know size of MATRICE
	int *A;
	int n;

public:	
	int getterN(){
		return n;
	}
	Matrix(){
		this -> n = 3;
		A = (int *)malloc((3 * (3 + 1)) / 2 * (sizeof(int)));
	}
	Matrix(int n){
		this -> n = n;
		A = (int *)malloc((n * (n + 1)) / 2 * (sizeof(int)));
	}
	void Rowset(int i, int j, int x)
	{
		//for lower matrice i >= j
		if (i >= j)
		{
			A[(i * (i - 1) / 2) + (j - 1)] = x;
		}
		else
		{
			A[(i * (i - 1) / 2) + (j - 1)] = 0;
		}
	}
	void Columnset(int i, int j, int x)
	{
		//for lower matrice i >= j
		if (i >= j)
		{
			A[n * (j - 1) - (j - 1) * (j - 2) / 2 + i - j] = x;
		}
		else
		{
			A[n * (j - 1) - (j - 1) * (j - 2) / 2 + i - j] = 0;
		}
	}

	int Rowget(int i, int j)
	{

		if (i >= j)
		{
			return A[(i * (i - 1) / 2) + (j - 1)];
		}
		else
			return 0;
	}
	int Columnget(int i, int j)
	{

		if (i >= j)
		{
			return A[n * (j - 1) - (j - 1) * (j - 2) / 2 + i - j];
		}
		else
			return 0;
	}

	void RowDisplay()
	{
		int i, j;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i >= j)
				{
					cout << " " << A[(i * (i - 1) / 2) + (j - 1)];
				}
				else
				{
					cout << " 0";
				}
			}
			cout << endl;
		}
	}
	void ColumnDisplay()
	{
		int i, j;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i >= j)
				{
					cout << " " << A[n * (j - 1) - (j - 1) * (j - 2) / 2 + i - j];
				}
				else
				{
					cout << " 0";
				}
			}
			cout << endl;
		}
	}
};

int main()
{
	int d;
	cout<<"Enter Dimension : "<<endl;
	cin >> d;
	Matrix m(d) ;
	cout<<"Enter Array Elements : "<<endl;
	// = Matrix(4);
	int i, j;
	int store;
	for (i = 1; i <= m.getterN() ; i++)
	{
		for (j = 1; j <= m.getterN() ; j++)
		{
			cin >> store;
			m.Rowset(i,j,store);
			// m.Columnset(i, j, store);
		}
		cout <<endl;
	}
		// m.ColumnDisplay();

	m.RowDisplay();

	return 0;
}