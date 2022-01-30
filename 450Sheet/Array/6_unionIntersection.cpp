#include <bits/stdc++.h>
using namespace std;

int getCountUnion(int *A, int *B, int m, int n)
{

	int count = 0;
	int i = 0, j = 0;

	while (i < m && j < n)
	{

		if (A[i] < B[j])
		{
			// cout << A[i++] << " ";
			count++;
		}
		else if (A[i] > B[j])
		{
			// cout << B[j++] << " "; //we will print and increment the value of j
			count++;
		}
		else
		{
			//this will run when A[i] and B[j] is same
			// cout << A[i++] << " ";
			count++;
			j++;
		}
	}
	
	while (i < m)
	{
		// cout << A[i++] << " ";
		count++;
	}

	while (j < n)
	{
		// cout << B[j++] << " ";
		count++;
	}

	// cout << endl;
	return count;
}

int doUnion(int A[] , int m , int B[] , int n) {

	set<int> st;
	for(int i = 0 ; i < m ; i++){
		st.insert(A[i]);
	}
	for(int i = 0 ; i < n ; i++){
		st.insert(B[i]);
	}

	cout<< st.size()<<endl;
	return (st.size());
}

int main()
{

	int *A, m;
	int *B, n;
	cin >> m >> n;
	A = new int[m];
	B = new int[n];

	for (int i = 0; i < m; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}

	// cout <<getCountUnion(A, B, m, n)<< endl;
	cout <<doUnion(A,m,B, n)<< endl;

	return 0;
}