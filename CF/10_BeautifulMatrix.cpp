
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
    int n = 5; 
    int temp = 0 ; 
    vvi matrix(5,vector<int> (5,0));
    int r,c;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n  ;j ++){
            cin>>temp;
            matrix[i][j] = temp;

            if(matrix[i][j] == 1){
                r = i;
                c = j ;
            }

        }
    }


    int o = 0 ;
    

    if(r < 2){
        if(r == 0) o += 2;
        else if(r == 1) o++;
         
    }else if(r > 2){
        if(r == 3) o++;
        else if(r == 4) o +=2;
    }

    if(c < 2){
        if(c == 0) o += 2;
        else if(c == 1) o++;
         
    }else if(c > 2){
        if(c == 3) o++;
        else if(c == 4) o +=2;
    }
    cout<<o;

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


