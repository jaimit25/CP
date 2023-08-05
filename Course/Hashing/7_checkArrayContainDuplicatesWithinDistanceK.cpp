
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;




void solve()
{

	int k = 3;
	vi  a = {1, 2, 3, 4, 1, 2, 3, 4};

	unordered_map<int,int> mp; // {element:index_of_last_occurence}

	for(int i = 0 ; i < a.size();i++){
		if(mp.find(a[i]) == mp.end()){
			//element not present
			mp[a[i]] = i;
		}
		else{
			// TWO CASES 
			//  - element lies last within k distance (map will give it's last occurence)
			// 	- element do not lie within k distance
			if( i - mp[a[i]] <= k){
				cout<<"Element lies within k distance"<<endl;
				return ;
			}
			else{
				//update last occurence (indx) of current elemtn in map
				mp[a[i]] = i;
			}

		}

	}
	cout<<"Element do not lie within k distance";

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



