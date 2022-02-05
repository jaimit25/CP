#include <iostream>
using namespace std;

int Comb(int n, int r)
{

    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return Comb(n - 1, r - 1) + Comb(n - 1, r);
    }
}

int fac(int n)
{

    if (n == 0)
        return 1;
    else
        return fac(n - 1) * n;
}

int CombSimple(int n, int r)
{
    int t0, t1, t2;
    t0=fac(n);
    t1=fac(r);
    t2=fac(n-r);
    return t0/(t1*t2);
}

int main()
{

   cout << Comb(4, 2) << endl;
   cout << CombSimple(4, 2) << endl;
    return 0;
}