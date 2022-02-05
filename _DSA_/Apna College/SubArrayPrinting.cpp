#include <iostream>
using namespace std;

int main()
{

	int A[] = {-1, 4, 7, 2}, n = 4;
	int st = 0, en = 0;
	int l = 0;

	for (int i = 0; i < n; i++)
	{
		st = en = i;

		while (en <= n)
		{
			l = st;
			while (l <= en)
			{
				cout << A[l] << " ";
				l++;
			}
			cout<<endl;
			en++;
		}
		
	}

	return 0;
}