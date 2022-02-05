#include <iostream>
using namespace std;

int combination(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return combination(n - 1, r - 1) + combination(n - 1, r);
    }
}

int factorial(int n)
{

    if (n == 0)
        return 1;
    else
        return factorial(n - 1) * n;
}

int fibonnaciusingloop(int n)
{
    int t0 = 0, t1 = 1, s;
    //value of n is either 0 or 1
    if (n <= 1)
    {
        return n;
    }
    for (int i = 2; i < n; i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

int fibo(int n){
    if(n<=1)
    return 1;
    else
    return fibo(n-2)+fibo(n-1);
}

int power(int m, int n){
//the power is m*m*m*m*m*m....till n times
//but also we can write m*m*m*m*m...(n-1)*m
//so the formula is 

if(n==0)
return 1;
else
return power(m,n-1)*m;

}


int main()
{

    return 0;
}