#include <iostream>
using namespace std;

int main()
{
	int A[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
	int H[17] = {0};
	int k = 10;
	// Element to be found is 10
	//for 6 we will check if 4 is present/marked or not 

	for (int i = 0; i < 10; i++)
	{
		if(H[k-A[i]]  != 0){
			// cout<<k<<endl;
			cout<<"Element found at : "<<A[i]<<" "<<k-A[i]<< " =10" <<endl;
		}
		H[A[i]]++;
	}

	return 0;
}