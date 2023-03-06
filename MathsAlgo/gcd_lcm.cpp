#include<bits/stdc++.h>
#define ll long long int
#define pb             push_back
#define vi             vector <int>




using namespace std;
 
template<class T>
void print(T &a){
    for(auto it : a){
        cout<<it<<" ";
    }
    cout<<endl;
}

long long int gcd(long long int a ,long long int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

long long int lcm(long long int a ,long long  int b){
    //formula to calculate lcm
    return (a*b)/gcd(a,b);
}

void solve(){
   
   int a,b;
   cin >> a >> b;
   int lcm_ = lcm(a,b);
   int gcd_ = gcd(a,b);
   cout<< lcm_<<" "<<gcd_<<endl;
}
 
int main()
{
int t ; cin >>t ; while(t--) solve();
 
 
return 0;
}
 