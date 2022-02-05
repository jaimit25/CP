#include <iostream>
using namespace std;

class DiagonalMatrix
{

private:
	int *A;
	int n;

public:
	//default constructor
	DiagonalMatrix()
	{
		n = 2;
		A = new int[2];
	}

	DiagonalMatrix(int n)
	{
		this->n = n;
		A = new int[n];
	}

	void set(int i, int j, int x);
	int get(int i, int j);
	void Display();
	void Delete()
	{
		delete[] A;
	}
};

void DiagonalMatrix::set(int i, int j, int x)
{
	if (i == j)
	{
		A[i-1]= x;
	}
}

int DiagonalMatrix ::get(int i, int j)
{
	if (i == j)
	{
		return A[i - 1];
	}
	return 0;
}
void DiagonalMatrix ::Display()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if(i==j){
				cout<<" "<<A[i];
			}
			else	cout<<" 0";
		}
		cout<<endl;
	}
}

int main(){

	DiagonalMatrix m = DiagonalMatrix(4);
	m.set(1,1,3);
	m.set(2,2,9);
	m.set(3,3,2);
	m.set(4,4,1);
	cout<<m.get(2,2)<<endl;
	m.Display();
	m.Delete();
	return 0;
}