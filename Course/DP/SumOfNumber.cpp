    
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;




void solve()
{


    vector<int> a = {6,7,3,2,2};

    vi dp(a.size()+1,-1);

    for(int i = 0  ; i < a.size();i++){
        if(i == 0){
            dp[i] = a[0];
        }else{
            dp[i] = a[i] + dp[i-1];
        }
    }

    vi query = {0,3,4,2};
    for(auto it: query){
        cout<<dp[it]<<" ";
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



