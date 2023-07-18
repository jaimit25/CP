

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



int remove_ld(int n){
    // remove last digit
    string s = to_string(n);
    s.pop_back();
    return stoi(s);
}

int remove_sld(int n){
    // remove second last digit
    string s = to_string(n);
    int sz = s.size();
    char temp = s[sz-1];
    s.pop_back();
    s.pop_back();
    return stoi(s+temp);
}



void solve()
{

    int n ;
    cin>>n;
  

    if(n < 0){

        int rld = remove_ld(n);
        int rsld = remove_sld(n);

        if(rld > rsld) cout<<rld;
        else cout<<rsld;
    }else cout<< n ;


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


