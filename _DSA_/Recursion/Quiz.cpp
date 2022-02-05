#include <iostream>
using namespace std;
int fun(int n)
{
    int x = 1;
    if (n == 1)
        return 1;
    for (int k = 1; k < n; k++)
    {
        x = x + fun(k) * fun(n - k);
    }
    return x;
}
int main(){

    cout<<fun(5)<<endl;
    return 0;

}