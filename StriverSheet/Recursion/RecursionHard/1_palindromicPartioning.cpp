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
bool isPalin(string s, int start,int end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}


void help(int i , string &s, vector<string> &path, vector<vector<string>> &ans){
    if(i == s.size()){
         ans.push_back(path); 
         return;
    }
    for(int ind = i ; ind < s.size() ; ind++){
        if(isPalin(s,i,ind)){
            path.push_back(s.substr(i,ind-i+1));
            help(ind+1,s,path,ans);
            path.pop_back();
        }
    }
}



vector<vector<string>> partition(string&s) {
    vector<vector<string>> ans;
    vector<string> temp;
    help(0,s,temp,ans);
    return ans;
}



 
int main()
{

  string s = "aabb";
  vector < vector < string >> ans = partition(s);
  int n = ans.size();
  cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;
 
 
return 0;
}
 