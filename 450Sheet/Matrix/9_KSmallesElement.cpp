// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function

void print(int mat[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	int r;
	cin >> r;
	cout << kthSmallest(mat, n, r) << endl;
	// cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
	return 0;
}
// } Driver Code Ends

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
	priority_queue<int> q;
	int ans = INT32_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			q.push(-mat[i][j]);
		}
	}
	int j = 1;

	while (j != k)
	{
		cout << "popped : " << q.top() << endl;
		q.pop();
		j++;
	}
	ans = q.top();
	return (-ans);
}
// 4
// 10 20 30 40
// 15 25 35 45
// 24 29 37 48
// 32 33 39 50
// 7
