

#include<bits/stdc++.h>
#define ll long long int
#define F first 
#define S              second
#define pb             push_back
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vs             vector<string>
#define vvi            vector<vector<int>>
#define vvs            vector<vector<string>>
#define vvc            vector<vector<char>>
#define vvll            vector<vector<long long>>
#define svi            set<vector<int>> 
#define si             set <int>





using namespace std;
 
template<class T>
void print(T &a){
    for(auto it : a){
        cout<<it<<" ";
    }
    cout<<endl;
}

template<class T>
void print2(T &a){
    for(auto it : a){
        for(auto i : it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
}





void solve()
{
        int n ; cin>>n;
        vector<int> coins;
        int count = 0,ps = 0 ;

        int sum = 0 ;

        for(int i = 0 ; i < n ; i ++){
            int coin;
            cin>>coin;
            sum = sum + coin;
            coins.push_back(coin);
        }


        sum /= 2;
        sort(coins.begin(),coins.end());

        for(int i = n-1 ; i >= 0 ; i--){
            ps += coins[i];
            count++;
            if(ps > sum) break;
        }
        cout<<count;

 }



 
int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

 solve();
 
return 0;
}


