// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int *spirallyTraverse(int r, int c, vector<vector<int> > matrix)
// {
// 	int *ans;
// 	ans = new int[r * c];

// 	return ans;
// }

int main()
{

	int r, c;
	cin >> r >> c;
	vector<vector<int> > matrix;
	vector<int> val;
	int temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> temp;
			val.push_back(temp);
		}
		matrix.push_back(val);
		val.clear();
	}

	// int row_start = 0;
	// int row_end = r - 1;

	// int col_start = 0;
	// int col_end = c - 1;
	// vector<vector<int> > A = matrix;
	

	// while (row_start <= row_end && col_start <= col_end)
	// {
	// 	for (int col = col_start; col <= col_end; col++)
	// 		cout << A[row_start][col] << " ";
	// 	row_start++;

	// 	for (int row = row_start; row <= row_end; row++)
	// 		cout << A[row][col_end] << " ";
	// 	col_end--;

	// 	for (int col = col_end; col >= col_start; col--)
	// 		cout << A[row_end][col] << " ";
	// 	row_end--;

	// 	for (int row = row_end; row >= row_start; row--)
	// 		cout << A[row][col_start] << " ";
	// 	col_start++;
	// }

	// cout<<endl;

	// for (auto it : matrix)
	// 	for (auto v : it)
	// 	{
	// 		cout << v << " ";
	// 	}
	// 	cout << endl;
	// }

	// int BL = r - 1;

	int n = r;
	int m = c;
	int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;

	vector<int > ans;
	int temp;


	while (row_start <= row_end && column_start <= column_end)
	{
		// for row_start
		for (int col = column_start; col <= column_end; col++)
		{	
			ans.push_back(matrix[row_start][col]);
		}
		row_start++;

		// for column_end
		for (int row = row_start; row <= row_end; row++)
		{
			ans.push_back( matrix[row][column_end]);
		}
		column_end--;

		// for row_end
		for (int col = column_end; col >= column_start; col--)
		{
			ans.push_back(matrix[row_end][col]);
		}
		row_end--;

		// column_start
		for (int row = row_end; row >= row_start; row--)
		{
			ans.push_back(matrix[row][column_start]);
		}
		column_start++;
	}
	// cout << endl;

	return 0;
}

// 4
// 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

// LOOPING USING ARRAY
//   int A[r][c];
//   for (int i = 0; i < r; i++)
//   {
//   	for (int j = 0; j < c; j++)
//   	{
//   		cin >> A[i][j];
//   	}
//   }

// for (int i = 0; i < r; i++)
// {
// 	for (int j = 0; j < c; j++)
// 	{
// 		cout << A[i][j] << " ";
// 	}
// 	cout << endl;
// }