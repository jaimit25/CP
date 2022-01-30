#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
	vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
	{
		// code here.
		int i = 0, j = 0, k = 0;
		vector<int> ans;
		while (i < n1 && j < n2 && k < n3)
		{

			if (A[i] == B[j] && B[j] == C[k])
			{

				//this condition will check if there is no repeated element in the Array also if Array is sorted 
				//so we can chcek if the last element is equal to the present element
				if (ans.size() == 0 || ans.back() != A[i])
				{
					ans.push_back(A[i]);
				}
				// ans.push_back(A[i]);
			i++; j++; k++;

			}
			else if (A[i] < B[j])
				i++;
			else if (B[j] < C[k])
				j++;
			else
				k++;
		}
		for (auto it : ans)
		{
			cout << it << " ";
		}
		cout << endl;

		return ans;
	}
};

int main()
{

	Solution obj;
	int a, b, c;
	cin >> a >> b >> c;

	int *A;
	int *B;
	int *C;
	A = new int[a];
	B = new int[b];
	C = new int[c];

	for (int i = 0; i < a; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < b; i++)
	{
		cin >> B[i];
	}

	for (int i = 0; i < c; i++)
	{
		cin >> C[i];
	}
	obj.commonElements(A, B, C, a, b, c);

	return 0;
}