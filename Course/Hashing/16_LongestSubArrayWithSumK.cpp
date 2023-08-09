
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;


int lenOfLongSubarr(int A[],  int N, int k) 
    { 
       int sum = 0;
        int maxi = 0;
        unordered_map<int,int> mp;
        for(int i = 0;i<N;i++)
        {
            sum += A[i];
            if(sum==k)
            {
                maxi = max(maxi,i+1);
            }
            else if(mp.count(sum-k)>0)
            {
                maxi = max(maxi,i - mp[sum-k]);
            }
            if(mp.count(sum)==0)
            {
              mp[sum] = i;
            }
        }
        return maxi;
    } 

    
void solve()
{


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



