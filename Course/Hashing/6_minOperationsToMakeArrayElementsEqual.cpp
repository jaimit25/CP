
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void solve()
{
	
	vi a = {1,2,3,4,5,2,2,2};
	unordered_map<int,int> mp;
	
	for(auto it : a)
		mp[it]++;

	int maxf = 0;
	for(auto it : mp)
		maxf = max(maxf,it.second);

	cout<< "min Operations req is : "<< a.size() - maxf;

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



