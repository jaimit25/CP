#include<bits/stdc++.h>
#define ll long long int
#define push_back pb
#define F first 
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vvi vector<vector<int>>

using namespace std;
 
 



void solve(){

  vi a = {1,2,3,4};
  vi b = {1,4};
  set<int> s;

  for(auto it  : a){
    s.insert(it);
  }

  for(auto it : b){
    if(s.find(it) == s.end()){
      cout<<"false";
      return;
    }
  }
  cout<<"true";


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
 