// ./helloworls on terminal to run the program manually
// comman+shift +b
// stop code control + alt + m macos

#include <iostream>
using namespace std;
int main()
{

    int height;
    cout << "Enter Height Of Pyramid" << endl;
    cin >> height;
    int i, j;
    int num = 0;
    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    return 0;
}