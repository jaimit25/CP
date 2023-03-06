#include<bits/stdc++.h>
#define vi             vector <int>
#define pb     push_back

using namespace std;
 
template<class T>
void print(T &a){
    for(auto it : a){
        cout<<it<<" ";
    }
    cout<<endl;
}


void solve(){


int n;
cin>>n;


//// sieve of Erantosthenes Algorithm
// vector<int> sieve(n,0);
// for(int x = 2 ; x <= n ; x++){
//     if(sieve[x]) continue;
    
//     int u = 2;
//     while(u <= n){
//         sieve[u*x] = 1;
//         u++;
//     }
// }

////print
// for(int i = 2 ; i <= n ; i++){
//     cout<< i <<" : "<< sieve[i]<<endl;
// }



// To check if number is prime 
// int flag = 1 ;
// for(int  i = 2 ; i*i <= n ; i++){
//     if(n%i == 0 ) {
//         cout<< "false";
//         flag = 0;
//         break;
//     }
// }
// if(flag){
//     cout<< "true";
// }


// To get prime factors
// vi f;   
// for(int i = 2 ; i*i <= n ;i++ ){
//     while(n%i == 0 ){
//         f.push_back(i);
//         n = n/i;
//     }
// }
// if(n > 1) f.pb(n);
// print(f);


}



int main()
{

int t ; 
cin >> t; 

while(t--)
    solve();
 
 
return 0;
}

// 2 : 0
// 3 : 0
// 4 : 1
// 5 : 0
// 6 : 1
// 7 : 0
// 8 : 1
// 9 : 1
// 10 : 1
// 11 : 0
// 12 : 1
// 13 : 0
// 14 : 1
// 15 : 1
// 16 : 1
// 17 : 0
// 18 : 1
// 19 : 0

 