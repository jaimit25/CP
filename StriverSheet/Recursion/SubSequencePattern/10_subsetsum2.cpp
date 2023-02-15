#include<bits/stdc++.h>
#define ll long long int
#define F first 
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vvi vector<vector<int>>

using namespace std;
 
void print(vi &a){
	for(auto it : a){
		cout<<it<<" ";
	}
	cout<<endl;
}

void print2(vvi &a){
	for(auto it : a){
		for(auto i : it)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
}





void help(int i, vector<int> &nums, vector<int> &ds,set<vector<int>> &ans){
	if(i == nums.size()){
		ans.insert(ds);
		return ; 
	}

	ds.push_back(nums[i]);
	help(i+1,nums,ds,ans);
	ds.pop_back();
	help(i+1,nums,ds,ans);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	set<vector<int> > ans ;
	vector<int> temp;
	help(0,nums,temp,ans);
	vector<vector<int>> r ;

	for(auto it : ans){
		r.push_back(it);
	}

	return r;

}
 
int main()
{


vi a = {1,2,2};
vvi ans = subsetsWithDup(a);
print2(ans);
 
 
return 0;
}
 