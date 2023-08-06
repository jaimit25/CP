
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void solve()
{
    
    vi a = {1,1,1,1};
    int n = a.size();
    int k = 2;

    int count = 0;

    unordered_map<int,int> mp;
    for(int i =0; i < n ; i ++){
        int n = k - a[i];
        if(mp.find(n) != mp.end()){
            count += mp[n];
        }
         mp[a[i]]++;
    }
    return count;
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



