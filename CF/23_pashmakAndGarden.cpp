

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
    int x1,x2,y1,y2; // Already given
    int x3,x4,y3,y4; // yet to found

    cin>>x1>>y1>>x2>>y2;

    int dx = x1-x2;
    int dy = y1-y2;

    if(dx == dy ){
        //diagonal top right coordinate
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
    }   
    else if(x1 == x2){
        // left top coordinate
        x3 = x4 = x1 + abs(y1-y2);
        y3 = y1;
        y4 = y2;
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
    }
    else if(y1 == y2){
        // right bottom coordinate
        y3 = y4 = y1 + abs(x1-x2);
        x3 = x1;
        x4 = x2;
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
    }
    else {
        cout<<-1;
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


