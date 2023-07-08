

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

bool isVowel(char ch){
    vector<char> vowel = {'A', 'O','Y', 'E', 'U', 'I','a','o','y','e','u','i'};
    return find(vowel.begin(),vowel.end(),ch) != vowel.end();
}



void solve()
{
    string s ;
    cin>>s;
    string temp = "";

    if(s.length()){
        for(int i = 0 ; i < s.length(); i++){
            if(!isVowel(s[i])) temp =  temp + "." + (char)tolower(s[i]) ;
        }
    }
    cout<<temp<<endl;
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


