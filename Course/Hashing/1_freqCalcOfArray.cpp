
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void solve()
{
	vector<int> a = {1,3,1,1,2,4,6};
	vector<int> b(a.size(),0);

	for(auto it : a){
		b[it]++;
	}
	for(int i = 0 ; i < b.size();i++){
		cout<<i<<" : "<<b[i]<<endl;
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



