#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{

    int *P = new int[5];
    //created an array

   
    cout << "Enter Array Elements : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> P[i];
    }

    cout << "Printing Array Elements : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << " " << P[i];
    }

    cout << endl;
     // now increasing size of an array
    int *Q = new int[10];
    
    for (int i = 0; i < 5; i++)
    {
      Q[i]=  P[i];
    }
    delete [] P;
    P = Q;
    cout << "Printing Array Elements : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << P[i] << endl;
    }
    Q = NULL;

    return 0;
}