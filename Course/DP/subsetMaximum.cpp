#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;


void findMax(vi&a,int i,int mxm){

	if(a.size() == i){
		cout<<mxm<<endl;
		return ;
	}
	

	mxm = mxm+a[i];
	findMax(a,i+1,mxm);

	mxm = mxm-a[i];
	findMax(a,i+1,mxm);
}

void solve()
{


	vi a = {2,4,6,7,8};
	findMax(a,0,0);


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



