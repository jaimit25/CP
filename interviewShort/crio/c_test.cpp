// #include <bits/stdc++.h>
// using namespace std;

// //Question 3
// // vector<long long> circularSquare(int n, vector<vector<int>> mat, int q, vector<vector<int>> query)
// // {

// //   vector<long long> ans(q, 0);
// //     for (int i = 0; i < q; i++)
// //     {
// //         int x = query[i][0], y = query[i][1], r = query[i][2];
// //         long long sum = 0;
// //         for (int j = 0; j < n; j++)
// //         {
// //             for (int k = 0; k < n; k++)
// //             {
// //                 if (abs(x - j) + abs(y - k) <= r)
// //                 {
// //                     sum += mat[j][k];
// //                 }
// //             }
// //         }

// //         ans[i] = sum;
// //     }
// //     return ans;
// // }

// // int main()
// // {
// //     int n;
// //     cin >> n;

// //     vector<vector<int>> mat(n);

// //     for (int i = 0; i < n; i++)
// //     {
// //         for (int j = 0; j < n; j++)
// //         {
// //             int val;
// //             cin >> val;

// //             mat[i].push_back(val);
// //         }
// //     }

// //     int q;
// //     cin >> q;

// //     vector<vector<int>> query;

// //     for (int i = 0; i < q; i++)
// //     {
// //         int x, y, r;
// //         cin >> x >> y >> r;

// //         query.push_back({x, y, r});
// //     }

// //     vector<long long> ans = circularSquare(n, mat, q, query);

// //     for (auto i : ans)
// //     {
// //         cout << i << endl;
// //     }
// // }

// Rick is a gardener and want to plant some flowers in a area with N*N spaces. Each space has a cost associated with it to plant flowers. And he also wants to plant flowers in a pattern.

// He will give you a radius R and a cell location Xth row and Yth column (0th base indexing). He will plant the flowers in all the cells (X1, Y1) satisfying the condition of abs(X-X1) + abs(Y-Y1) <= R.

// He is trying to figure out the cost for several possible locations. He is not good with calculation so you need to answer Q queries of him planting flowers cost with location provided (X, Y, R).

// Input format
// First line contains an integer N.

// Next N lines contain N integers representing the cost of each cell.

// Next line consists of an integer Q.

// Next Q line contains three integers X, Y and R representing cell location and radius.

// Output format
// For each query print the cost of planting flowers according to condition in a new line.

// Sample Input 1
// 3

// 1 2 3

// 4 5 6

// 7 8 9

// 2

// 1 1 1

// 0 0 3

// Sample Output 1
// 25

// 36

// Explanation
// For first query sum will be of (1,1), (0,1), (2,1), (1,0) and (1,2)

// The second query sum will be all cells except (2,2) cells because this is the only cell not satisfying the condition.

// Constraints
// 1 <= N <= 10^3

// 1 <= Cost <= 10^9

// 1 <= Q <= 10^3

// 0 <= X,Y <= N-1

// 0 <= R <= 10^9a