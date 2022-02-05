#include <iostream>
using namespace std;

int main()
{
	int A[] = {1, 2, 3, 7, 5}, n = 5;
	int st, en;
	st = en = 0;
	int sum = 5;
	int cal = 0;

	for (st = 0; st < n; st++)
	{
		en = st;
		cal = 0;
		while (cal != sum && cal < sum)
		{
			cal = cal + A[en];
			// cout << "Calculated value : " << cal << endl;
			en++;
		}
		if (cal == sum)
		{
			cout << st << " " << en - 1 << endl;
			break;
		}
	}

	if(st == n){
		cout<<endl<<"404, Not Found "<<endl;
	}

	return 0;
}