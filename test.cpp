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



//APPROACH 1- USING RECURSION 
int help(string &s, int i , vector<string> &wordDict, bool &ans,vector<int> &dp){

    if(i == s.size()) {
        ans = true;
        return 1;
    }   

    int res=0;
    for(auto it : wordDict){
        if(s.substr(i,it.size()) == it){
          int res = help(s,i + it.size(),wordDict,ans,dp);
          if(res == 1) break;
        }
    }

    return res;
}

bool wordBreak(string s, vector<string>& wordDict) {
    bool ans = false;
    vector<int> dp(s.size(),-1);

    int res = help(s,0,wordDict,ans,dp);

    return ans;
}

 
int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


// string s = "neetcode";
// vs wd = {"neet","leet","code"};

// string s  = "catsandog";
// vs wd = {"cats","dog","sand","and","cat"};

string s = "applepenapple";
vs wd = {"apple","pen"};


if(wordBreak(s,wd)){
        cout<<"TRUE"<<endl;
  }
else cout<<"FALSE"<<endl;
 
return 0;
}
 