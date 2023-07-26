

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
    long long n , k ; 
    cin>>n>>k;
    vector<long long> a;

    int i = 1 ; 
    long long ps = 0 ;
    while(i <= n){
        ps += i*5;
        a.push_back(ps);
        i++;
    }

    long long t = 240 - k;

    // search element in prefix Array a where value is just smaller or equal to t
    int l = 0;
    int r = n-1;
    long long ans = 0 ;
    int ind =-1;

    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid] <= t){
            ans = a[mid];
            ind = mid;
            l = mid+1;
        }
        else{
            r = mid - 1;
        }
        
    }
    // cout<<ans;
    cout<<ind+1;

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


