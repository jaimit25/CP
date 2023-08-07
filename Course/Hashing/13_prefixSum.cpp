
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;


 int maxLen(vector<int>&a, int n)
    {   
        unordered_map<int,int> mp; // {prefixSum , indexOfFirstoccurence_of_ps}
        int maxlen = 0 ; 
        int sum = 0 ; 
        for(int i = 0;  i < n ; i++){
            sum += a[i];
            if(sum == 0 ) maxlen = max(maxlen,i+1);
            else{
                if(mp.find(sum) != mp.end()){
                    maxlen = max(maxlen, i - mp[sum]);
                }else{
                    mp[sum]= i;
                }
            }
        }
        return maxlen;
    }


void solve()
{
	// ps[r] = ps[l-1] + sum[l...r]; 
	// for subArray with sum 0 ps[r] = ps[l-1] + 0;
	// so we just have to find(ps[r]) where, ps[r] == ps[l-1];
	// ps[l-1] will be stored in map {ps,indexOfFirstOccurence};


	vi a = {15,-2,2,-8,1,7,10,23};
	cout<<maxlen(a,a.size());

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



