#include <stdio.h>
#include "Queues.h"

void BFS(int G[][7], int start, int n)
{
	int i = start, j;

	int visited[7] = {0};

	printf("%d ", i);
	visited[i] = 1;
	enqueue(i);

	while (!isEmpty())
	{
		//dequeue next address from Queue
		i = dequeue();
		for (j = 1; j < n; j++)
		{
			if (G[i][j] == 1 && visited[j] == 0)
			{
				printf("%d ", j);
				visited[j] = 1;
				enqueue(j);
			}
		}
	}
}

void DFS(int G[][7], int start, int n)
{
	//intializing all values with 0 and making it static so everytime
	//when function is called we wont create same array for every call in stack frame
	static int visited[7] = {0};
	int j;

	if (visited[start] == 0)
	{
		//once we vist any vertex we print the value and mark it as one in the static Array
		printf("%d ", start);
		visited[start] = 1;

		// ..we will start exploring the vertex
		for (j = 1; j < n; j++)
		{
			//we are checking if there is an edge and also if it is visited or not 
			if (G[start][j] == 1 && visited[j] == 0)
				// ..we are using system stack to print out the graph value
				DFS(G, j, n);
		}
	}
}
int main()
{
	//Adjancency Matrix for the Graph

			//  0  1  3  4  5  6  7
	int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},  //0
		       {0, 0, 1, 1, 0, 0, 0},  //0
		       {0, 1, 0, 0, 1, 0, 0},  //0
		       {0, 1, 0, 0, 1, 0, 0},  //0
		       {0, 0, 1, 1, 0, 1, 1},  //0
		       {0, 0, 0, 0, 1, 0, 0},  //0
		       {0, 0, 0, 0, 1, 0, 0}}; //0

	//Depth first search for the graph
	DFS(G, 4, 7);

	cout << endl;

	//Breadth first search for the graph
	BFS(G, 1, 7);

	return 0;
}