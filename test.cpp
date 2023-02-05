#include<bits/stdc++.h>
#define ll long long int
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
 


void print(vi&a){
    for(auto it :a) cout<<it<<" ";
    cout<<endl;
}

vector<int> returnLps(string &s){

    int n = s.size();
    vector<int> lps(n,0);

    int i = 1 , j = 0 ; 
    while(i<n){
        if(s[i] == s[j]) {
            lps[i] = j+1;
            i++;j++;
        }
        else{
            // we have not yet starte checking pattern of j is at 0 
            if(j == 0){
                lps[i] = 0 ; 
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    return lps;
}



string longestPrefix(string &s) {
        
    vector<int> lps = returnLps(s);
    print(lps);
    
    int mxm = 0 ; 
    for(int i = 0 ; i < lps.size() ; i++){
        mxm = max(mxm,lps[i]);
    }

    //we need the length of the longest suffix which has the last character of the pattern 
    // ie for "bba"
    // every suffix should include the "a" - example= "a","ba","bba"
    int len_suffixWithLastChar = lps[lps.size()-1];

    return s.substr(0,len_suffixWithLastChar);
}


 
int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

// string s = "bba";
string s = "level";
 cout<<longestPrefix(s)<<endl;

 
return 0;
}
 