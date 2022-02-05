#include <iostream>
using namespace std;

//taylor series using hornes rule
float e(float x, float n)
{

    static float s = 1;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + x / n * s;
        return e(x, n - 1);
    }
}

//using for loop
float eloop(float x, float n)
{
    float s = 1;
    int i;
    float num = 1;
    float den = 1;
    for (i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}
int main()
{

    cout << e(3, 10) << endl;
    cout << eloop(3, 10) << endl;
    return 0;
    
}