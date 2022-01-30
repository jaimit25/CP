// ./helloworls on terminal to run the program manually
//comman+shift +b
//stop code control + alt + m macos

#include <iostream>
using namespace std;
int main()
{

    //    *         *  4   1  6-2*1 =4
    //    * *     * *  2   2  6-2*2 =2
    //    * * * * * *  0   3  6-2*3 =0

    int height;
    cout << "Enter The Height Of 1/4th of a Pyramid" << endl;
    cin >> height;
    int i, j;

    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << " * ";
        }
        for (j = 1; j <= 2 * height - 2 * i; j++)
        {
            cout << "   ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }

    for (i = height; i > 0; i--)
    {
        // cout<<"Run Time :"<< i<<endl;

        for (j = 1; j <= i; j++)
        {
            cout << " * ";
        }
        for (j = 1; j <= 2 * height - 2 * i; j++)
        {
            cout << "   ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }

    return 0;
}