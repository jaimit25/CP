

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

    int r,c ;
    cin>>r>>c;
    vi vr(r),vc(c);

    for(int i = 0 ; i < r ; i++){
        string s ; 
        cin>>s;
        for(int j = 0  ; j < c ; j++ ){
            if(s[j] =='S'){
                vr[i] = 1;
                vc[j] = 1;
            }
        }
    }

    int count =0 ;

    for(int i = 0 ; i < r ; i++){
        for(int j = 0  ; j < c ; j++ ){
            if(vr[i] == 0 || vc[j] == 0){
                count++;
            }
        }
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


