
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;



int findSubArraySum(int Arr[], int N, int k)
    {
       unordered_map<int,int> mp; // {prefixSum:noOfOccurr}

        int sum =0 ; 
        int count = 0 ;
        for(int i =0 ; i < N ;i++){
            sum += Arr[i];
            if(sum == k) count++;
            if(mp.find(sum-k) != mp.end()){
                count+=mp[sum-k]; 
            }
            mp[sum]++;
        }
        return count;
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



