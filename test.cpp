

#include<bits/stdc++.h>
#define ll long long int
#define F first 
#define S               second
#define pb              push_back
#define vi              vector <int>
#define pii             pair <int, int>
#define vpi             vector <pii>
#define vpp             vector <pair<int, pii>>
#define mii             map <int, int>
#define mpi             map <pii, int>
#define spi             set <pii>
#define vs              vector<string>
#define vvi             vector<vector<int>>
#define vvs             vector<vector<string>>
#define vvc             vector<vector<char>>
#define vvll            vector<vector<long long>>
#define svi             set<vector<int>> 
#define si              set <int>
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define bitcount        __builtin_popcount 
#define pb              push_back 
#define fill(a,v)       memset(a, v, sizeof a) 
#define FOR(i,a,b)      for(int i=a;i<b;i++) 
#define DB(x)           cout<<#x<<"="<<x<<"\n";
#define all(vec)        vec.begin(),vec.end() 
#define rall(vec)       vec.rbegin(),vec.rend() 
#define sz(r)           r.size() 
#define rem1(v, i)      (v.erase(v.begin()+i)) 
#define rem2(v, i, j)   (v.erase(v.begin()+i, v.begin()+j+1)) 
#define MAXV(v)         *max_element(v.begin(),v.end()) 
#define MINV(v)         *min_element(v.begin(),v.end()) 
#define ull unsigned long long 
#define ll long long int 
#define ld long double 
#define PI 3.14159265
#define SIZE 100000001 
#define INF 0x7fffffff 
//const int MX = 1e5+5; 
int dx[] = {1,0,-1,0}; 
int dy[] = {0,1,0,-1}; 
int ddx[] = {1,0,-1,0,1,-1,-1,1}; 
int ddy[] = {0,1,0,-1,1,-1,1,-1}; 



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



ll sm(ll no){
    
    ll s = 0 ;
    while(no){
        s = no%10 + s;
        no /= 10;
    }
    return s;
}

void solve()
{
    // vector<ll> b = {51, 71, 17, 42};
    vector<ll> b = {51 ,32 ,43 };
    unordered_map<ll,ll> mp; // sum : ele
    ll maxPair = -1; 


    for(auto it : b){
      if(mp.find(sm(it)) != mp.end()) {
        ll pp = it + mp[sm(it)];
        maxPair = max(maxPair, pp);
        mp[sm(it)] = max(mp[sm(it)],it) ; 
      }else{
        mp[sm(it)] = it;
      }
    }
    cout<<maxPair;
}
 
int main()
{
fastread();
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

 solve();
 
return 0;
}


