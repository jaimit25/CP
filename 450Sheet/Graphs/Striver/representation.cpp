#include <iostream>
#include <vector>
using namespace std;

int main()
{

	// 2D matrix is also known as Adjancency matrix
	//number of nodes -n ..4 | no of edges -m..4
	//represention of undirected Graph

	// Graph
	//     {1, 2},
	//     {2, 3},
	//     {1, 4},
	//     {3, 4},

	// 1,2 we mark 2,1 in matrix as graph is undirected
	int A[5][5]; // graph with 4,4 nodes and edges
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			A[i][j] = 0;
		}
	}
	int val1, val2;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i != 0 && j != 0)
			{
				cin >> val1 >> val2;
			}
		}
	}

	//using vector to create Adjacency list as Adjacency matrix takes Space
	vector<int> adj[5];

	// 0|
	// 1| (2,4)
	// 2| (1,3)
	// 3| (2,4)
	// 4| (3,1)

	//Weighted Graph
	vector < pair<int, int>> adj[5];
	// 0|
	// 1| (2,1)(3,4)
	// 2| (1,1)(3,2)
	// 3| (2,1)(1,4)


	return 0;