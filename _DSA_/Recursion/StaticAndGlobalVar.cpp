#include <iostream>
using namespace std;

    //Declaring variable Globally
    int x = 0;

int fun(int n)
{
    //declaring variable statically
    // static int x=0;

    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{

    cout << fun(5) << endl;
    return 0;
}