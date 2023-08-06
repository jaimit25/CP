
#include<bits/stdc++.h>
#define vi vector<int>


using namespace std;
void print(vi &a){
	for(auto it : a){
		cout<<it <<" ";
	}
	cout<<endl;
}

void solve()
{	
	int n ,q;
	cin>>n;

	vi a;
	while(n){
		int temp;
		cin>>temp;
		a.push_back(temp);
		n--;
	}

	n = a.size();
	int i = 0; 
	vi ps(n);
	for(i = 0 ;i < n ; i++)
		ps[i] = a[i]+ps[i-1]; //ps[-1] will give 0
	
	// print(ps);

	cin>>q;
	while(q){
		int start,end; cin>>start>>end;
		cout<<ps[end] - ps[start-1]<<endl;
		q--;
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



