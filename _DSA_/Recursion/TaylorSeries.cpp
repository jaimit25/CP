#include <iostream>
using namespace std;

//number of times e is repeated
//x is power of e and n is no of times it is repeated
float TaylorSeries(float x, float n)
{

    static float p = 1, f = 1;
   if (n == 0)
    {
        return 1;
    }
    else
    {
        float r = TaylorSeries(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

int main()
{
    cout<<TaylorSeries(3,10)<<endl;;
    return 0;
}