// 12 Sept 2021

#include <iostream>
using namespace std;


void swap(int *x , int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print(int *A){
	for(int i = 0 ; i < 7 ; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main()
{

	int A[] = {1, 2, 3, 4, 5, 6, 7};
	print(A);
	int i, j;
	for (i = 0, j = 6; i < j; i++, j--)
	{
		swap(A[i],A[j]);
	}
	print(A);

	return 0;
}