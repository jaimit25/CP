#include <iostream>
using namespace std;

//using loops
int usingloop(int n)
{

    int k = 0;
    for (int i = 0; i <= n; i++)
    {
        k = k + i;
    }
    return k;
}

//using recursion
int recursion(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return recursion(n - 1) + n;
    }
}

//using formula
int formula(int n)
{
    if (n == 0)
    {

        return 0;
    }
    else
    {
        n = (n * (n + 1)) / 2;
        return n;
    }
}

int main()
{
    cout << usingloop(3) << endl;
    cout << formula(3) << endl;
    cout << recursion(3) << endl;
    return 0;
}

//  practise recursion
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sum(n - 1) + n;
    }
}
