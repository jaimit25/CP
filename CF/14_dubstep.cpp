

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

    int n ; cin >> n ;
    vvi teams;


    while(n){
        int h,g;
        vi temp;
        cin>>h>>g;
        temp.push_back(h);
        temp.push_back(g);
        teams.push_back(temp);
        n--;
    }
    int count = 0 ;
    for(int i = 0 ; i < teams.size();i++)
    {
        for(int j = 0 ; j < teams.size();j++){
            if(i!=j){
                if(teams[i][0] == teams[j][1]){
                    count++;
                }

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


