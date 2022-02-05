#include <iostream>
using namespace std;

int main()
{

	int A[5][6] = {
	    {1, 5, 7, 9, 10, 11},
	    {6, 10, 12, 13, 20, 21},
	    {9, 25, 29, 30, 32, 41},
	    {15, 55, 59, 63, 68, 70},
	    {40, 70, 79, 81, 95, 105}};

	int n = 5, m = 6;

	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	//printing in spiral order

	int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;

	while (row_start <= row_end && column_start <= column_end)
	{
		//for row_start
		for (int col = column_start; col <= column_end ; col++){
			cout<< A[row_start][col]<<" ";
		}
		row_start++;

		//for column_end
		for(int row = row_start ; row <= row_end ; row++){
			cout<<A[row][column_end]<<" ";
		}
		column_end--;

		//for row_end
		for (int col = column_end; col >= column_start ; col--){
			cout<< A[row_end][col]<<" ";
		}
		row_end--;

		//column_start
		for(int row = row_end ; row >= row_start ; row--){
			cout<<A[row][column_start]<<" ";
		}
		column_start++;

	}

	return 0;
}