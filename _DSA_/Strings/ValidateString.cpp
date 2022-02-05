#include <iostream>
#include<stdio.h>
using namespace std;

int validateString(char *A)
{

	int i = 0;
	for (i = 0; A[i] != '\0'; i++)
	{
		if(
			!((A[i] >= 'a' &&
			A[i] <= 'z') )
			&&
			!((A[i] >= 'A' &&
			A[i] <= 'Z') ) 
			&&
			!((A[i] >= 48 &&
			A[i] <= 57)  ) 
			&&
			!(A[i] == ' ')
			)
			{
				return 0 ; //Invalid String
			}
			
	}

	return 1;
}

int main()
{

	char *name = "Anil There";
	if (validateString(name))
	{
		cout << "Valid String" << endl;
	}
	else
	{
		cout << "Not Valid String" << endl;
	}

	return 0;
}