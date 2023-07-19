

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



void sort2DVector(vvi& vec) {
    for (auto& innerVec : vec) {
        sort(innerVec.begin(), innerVec.end());
    }
}


void solve()
{
    int n ; 
    cin>>n;

    vi s(n+1,0);
    int i = 1 ;

    while(cin>>s[i])
        i++;
    
    
    vvi v(4);
    for(int i = 1 ; i <= n ; i++){
        if(s[i] == 1){
            v[1].push_back(i);
        }
        else if(s[i] == 2) {
            v[2].push_back(i);
        }else v[3].push_back(i);
    }

    sort2DVector(v);
    int minm = min(v[1].size(),v[2].size());
    int v3size = v[3].size();
    minm = std::min(minm,v3size);

    cout<<minm<<endl;

   i = 0;
    while(minm){
        cout<<v[1][i]<<" "<< v[2][i]<<" "<<v[3][i]<<endl;
        minm--;
        i++;
    }

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


