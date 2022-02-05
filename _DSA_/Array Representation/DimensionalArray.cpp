#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{

    //3 Different Ways of creating an Multidimensional Array

    int A[3][4] = {{1, 2, 3, 75}, {2, 3, 4, 9}, {5, 6, 78}};
    cout << " Printing First Array " << endl;

    //in stack
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << endl;
        }
    }
    cout << "****************************************************************" << endl;

    int *B[3];
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));
    //2D Array in Heap with pointer array in stack

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            B[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << B[i][j] << endl;
        }
    }

    cout << "****************************************************************" << endl;
    int **C;
    //Assigning space for pointer Array in heap memory
    C = (int **)malloc(3 * sizeof(int));

    //Assigning each memory block an Array
    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C[i][j] = i + j;
        }
    }
    //printing The Array Elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << C[i][j] << endl;
        }
    }

    cout << "****************************************************************" << endl;
    return 0;
}