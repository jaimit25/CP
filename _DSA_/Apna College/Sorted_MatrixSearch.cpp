
// | 1   4   7  11 |
// | 2   5   8  12 |
// | 3   6   9  16 |
// | 10 13  14  17 |

// | _   _   _   _ |
// | _  <x   x   _ |
// | _   _  >x   _ |
// | _   _   _   _ |

// At each element suppose x we have choice to go left or right

#include "bits/stdc++.h"
using namespace std;
int32_t main()
{
	int n, m;
	cin >> n >> m;
	int target;
	cin >> target;
	int mat[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	bool found = false;
	int r = 0, c = n - 1;
	while (r < m && c >= 0)
	{
		if (mat[r][c] == target)
		{
			found = true;
		}
		mat[r][c] > target ? c-- : r++;
	}
	if (found)
		cout << "Found";
	else
		cout << "Not Found";
}