#include <iostream>
using namespace std;

int main()
{

	int A[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};

	int key = 9;

	cout<<"2D Array : "<<endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"Searching a key in Array"<<endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(A[i][j] == key){
				cout<<"Key found"<<endl;
				break;
			}
			if(i == 2 && j ==2){
				cout<<"Key not found"<<endl;
			}
		}
	
	}


	return 0;
}