#include <iostream>
using namespace std;

int fun(int n)
{

    if (n > 100)
    {
     
        return n - 10;
    }
    else
    {    cout<<n<<endl;
        return fun(fun(n + 11));
    }
}

int main()
{
    cout << "Enter value of n" << endl;
    int n;

    cin >> n;
    cout << fun(n) << endl;

    return 0;
}