
//use of pow(x,y function used in previous question with different approach)
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

//Iterative Solution
// double mypow(double x, int n)
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


//Recursive Solution 

long long int helper(long long int x ,long long int y){
        if(y == 0) return 1;
     long long int mod = 1000000007;

        long long int res = helper(x,y/2); 

         // storing answers that are too large for their respective datatypes is an issue with this method.
        // In such instances, you must use modulus (%). Instead of finding x^n, you must find (x^n) % M.
            
        if(y%2 == 0 ) 
            return (res*res)%mod;
        
        return (x*res*res)%mod;
 }

long long int mypow(long long int x ,long long int y){
   return y < 0 ? 1/helper(x,y) : helper(x,y);
}
    
int countGoodNumbers(long long n) {
   
    long long int mod = 1000000007;
    
    double left = (n%2==1)?(n/2+1):(n/2);
    double right = n/2;
        
        return (int)((mypow(5, left)*mypow(4, right)) %mod); 
    }

int main()
{


double num = 2.0000;
int n  =  10 ;
cout<<mypow(num,n)<<endl;

 
 
return 0;
}
 