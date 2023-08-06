
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void solve()
{
    
    unordered_map<char,int> minf;
    vector<string> words = {"bella","label","roller"};

    //we will use minf to get the number of char repeatations in all the words together.
    for(char ch = 'a' ; ch <= 'z' ; ch++){
        minf[ch] = 1000;
    }

    for(auto it :words){
        unordered_map<char,int> mp;
        for(auto c : it)
            mp[c]++;
        for(char ch = 'a' ; ch<= 'z' ; ch++){
            minf[ch] = min(minf[ch],mp[ch]);
        }
    }

    vector<string> ans;

    for(char ch = 'a' ; ch<= 'z' ; ch++){
        while(minf[ch]){
            ans.push_back(string(1,ch));
            minf[ch]--;
        }
    }
    // return ans;

    for(auto it:ans){
        cout<<it<<" ";
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



