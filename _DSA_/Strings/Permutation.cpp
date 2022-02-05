#include <iostream>
using namespace std;

// void  perm( char s[] , int k){
// 	static int A[10] = {0};
// 	static char Res[10];
// 	int i;

// 	//acts as base condition. we loop through char array s and we call for all k level.
// 	if(s[k] == '\0'){
// 		Res[k] = '\0';
// 		cout<<Res<<endl;
// 	}
// 	else{
// 		for(i=0; s[i] != '\0' ; i++){
// 			if(A[i] == 0){
// 				Res[k] = s[i];
// 				A[i] = 1;
// 				perm(s,k+1);
// 				A[i] = 0;
// 			}
// 		}
// 	}
// }

void perm(char s[], int k)
{
	
	static char Res[5];
	static int A[5];
	int i;

	if (s[k] == '\0')
	{
		cout << Res << endl;
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (A[i] == 0)
		{
			Res[k] = s[i];
			A[i] = 1;
			perm(s, k + 1);
			A[i] = 0;
		}
	}
}

int main()
{

	char s[] = "ABC";
	perm(s, 0);

	return 0;
}