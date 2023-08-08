
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void solve()
{

vi a = {4, 2, 2, 6, 4};
int m = 6;

unordered_map<int,int> mp;
	
int xorAns = 0  ;int count =0 ; 

for(auto it : a){
	xorAns ^= it;
	if(xorAns == m)count++;
	if(mp.find(xorAns^m) != mp.end())
		count += mp[xorAns^m];
	mp[xorAns]++;
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




