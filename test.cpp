
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void solve()
{

    // // vi a = {1,1,2,2,2,1};
    // vi a = {3,2,1,2,1,4,5,8,6,7,4,2};
    vi a = {1};

    int maxDist = 0;
    unordered_map<int,int> mp; //{ele,ind}

    for(int i = 0 ; i < a.size(); i++){
        if(mp.find(a[i]) == mp.end()){
            //first time seen
            mp[a[i]] = i;
        }else{
            maxDist = max(maxDist,i-mp[a[i]]);
        }
    }
    cout<<maxDist;
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



