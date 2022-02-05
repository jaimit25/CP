#include <iostream>
using namespace std;

//using recursion
int fib(int n)
{
    if (n <= 0)
    {
        return n;
    }
    else
    {
        return fib(n - 2) + fib(n - 1);
    }
}

//using loop
int fibo(int n)
{
    int t0 = 0, t1 = 1, s;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int F[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int fibMem(int n)
{

    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {

        if (F[n - 2] == -1)
        {
            F[n - 2] = fibMem(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = fibMem(n - 1);
        }

        return F[n - 2] + F[n - 1];
    }
}

int main()
{

    cout << fib(4) << endl;
    cout << fibo(4) << endl;
    cout << fibMem(4)<<endl;
    return 0;
}