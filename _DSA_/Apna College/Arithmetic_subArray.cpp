#include <iostream>
using namespace std;

int main()
{

	int A[] = {
	    8,
	    7,
	    6,
	    5,
	    4,
	    6,
	    8,
	    10,
	},
	    n = 8;

	int j = 2;
	int cd = A[1] - A[0];
	int cal = 1;
	int max = -12;

	//looping through Array
	while (j < n)
	{
		if ((A[j] - A[j - 1]) == cd)
		{
			//cd is same
			cal++;
			//reached 2nd last index
			if (j == n - 1)
			{
				if (max < cal)
				{
					max = cal;
				}
			}
		}
		else if ((A[j] - A[j - 1]) != cd)
		{
			//cd is not same
			//so we update common difference and max value(if it is small)
			cd = A[j] - A[j - 1];
			if (cal > max)
			{
				max = cal;
			}
			cal = 1;
		}
		j++;
	}

	cout << endl;
	cout << " last common difference(cal) : " << cal << endl;
	cout << " Maximum length of common difference is(max) : " << max << endl;
	return 0;
}