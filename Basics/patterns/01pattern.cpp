#include <iostream>
using namespace std;
int main()
{
    //0 1 pattern

    int height;
    bool check = true;
    cout << "Enter height of the pyramid" << endl;
    cin >> height;
    int i = 1, j = 1;
    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (check)
            {
                cout << 1;
                check = !check;
            }
            else
            {
                cout << 0;
                check = !check;
            }
        }
        check = true;
        cout << endl;
    }
    return 0;
}