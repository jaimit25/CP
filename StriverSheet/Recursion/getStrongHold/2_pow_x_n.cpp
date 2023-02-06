#include<bits/stdc++.h>
#define ll long long int
#define F first 
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vvi vector<vector<int>>

using namespace std;


// double myPow(double x, int n)
// {
//      long long nn = (long long)n;

//      //make nn positive for now if n value is negative
//     if (nn < 0)
//         nn = -1 * nn;
//     double ans = 1.0;

//     while (nn)
//     {
//         if (nn % 2 == 1)
//         {
//             // odd
//             ans = ans * x;
//             nn = nn - 1;
//         }
//         else
//         {
//             // even
//             x = x * x;
//             nn = nn / 2;
//         }
//     }
//     return n < 0 ? (1.00 / ans) : ans;
// }

void helper(double &num , long long int &n , double &ans){
    if(n <= 0)
        return;

    if(n%2 == 0 ){
        num = num*num;
        n = n/2;
    }
    else{
        ans = ans*num;
        n = n-1;
    }
    helper(num,n,ans);
}

double myPow(double x, int n)
{   
    double ans = 1;
    long long int nn =n;
    if(nn < 0) nn = nn * -1;
    helper(x,nn,ans);
    return n < 0 ? 1.00/ans : ans;
}
 
int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

double num = 2.0000;
int n  =  10 ;
cout<<myPow(num,n)<<endl;

 
 
return 0;
}
 