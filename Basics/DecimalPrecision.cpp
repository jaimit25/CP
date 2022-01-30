#include <iostream>
#include <iomanip>
using namespace std;
#define repeat(n) for (int i = 0; i < n; i++)

int main()
{
    float a;
    repeat(10)
    {
        cout << "Enter The Value : " << endl;
        cin >> a;
        cout << fixed << setprecision(2)<< a << endl;
        cout<<"********************************"<<endl;

    }
    

    return 0;
}