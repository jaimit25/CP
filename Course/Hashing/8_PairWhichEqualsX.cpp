
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void solve()
{
	vi a = {0, -1, 2, -3, 1};
	int x = -2;
	unordered_set<int> s;
	
	for(int i = 0; i  < a.size();i++){
		int num = x - a[i];
		if(s.find(num) != s.end()){
			cout<<"TRUE";
			return ;
		}
		else
			s.insert(a[i]);
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



