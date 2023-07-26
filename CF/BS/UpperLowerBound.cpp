

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
    vi a = {2,3,5,6,8};
    print(a);

    int val = 2 ;



    /// [Lower bound program]
    int l = 0 ; 
    int r = a.size()-1;
    int ans = 0 ;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid] < val){
            l = mid + 1;
        }
        else if(a[mid]>= val){
            ans = a[mid];
            r = mid - 1;
        }
    }
    cout<<"Lower bound is : "<<ans<<endl;


    /// [Upper bound]
    l = 0 ;
    r = a.size()-1;
    ans = 0 ;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid] < val){
            l = mid + 1;
        }
        else if(a[mid] > val){
            ans = a[mid];
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout<<"Upper bound is : "<<ans<<endl;
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


