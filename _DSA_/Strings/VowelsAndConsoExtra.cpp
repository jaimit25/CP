#include<iostream>
using namespace std;

int main(){


	char A[] = "How are you";
	int i;
	int Vcount = 0, Ccount = 0;
	for( i = 0 ; A[i] != '\0' ; i++ )
	{
		if(
			A[i] == 'a' ||
			A[i] == 'e' ||
			A[i] == 'i' ||
			A[i] == 'o' ||
			A[i] == 'u' ||
			A[i] == 'A' ||
			A[i] == 'E' ||
			A[i] == 'I' ||
			A[i] == 'O' ||
			A[i] == 'U' )
			{
				Vcount++;
			}
		else if(
			(A[i] >= 'a' && A[i]  <= 'z') ||
			(A[i] >= 'A' && A[i]  <= 'Z') )
		{
				Ccount++;
		}
	}

	cout<<"Number of Volwels are : "<<Vcount<<endl;
	cout<<"Number of Consonant are : "<<Ccount<<endl;

	return 0;
}