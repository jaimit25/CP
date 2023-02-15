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

int getMedian(vi &temps)
{
	int n = temps.size();
	if(n%2 == 0){
		return temps[n/2]+temps[n/2+1];
	}
	return temps[(n/2)];
}
 

int add(vector<int> &a){
	int sum = 0 ;
	for(auto it  :a){
		sum = sum + it;
	}
	return sum;
}

void help(int i , vector<int> &nums, vector<vector<int> > &ans, vector<int> &ds ,int k, int n){
	if(ds.size() == k || i == nums.size()){
		if(add(ds) == n && k == ds.size()){
			ans.push_back(ds);
		}
		return ;
	}

	ds.push_back(nums[i]);
	help(i+1,nums,ans,ds,k,n);
	ds.pop_back();

	help(i+1,nums,ans,ds,k,n);
}

vector<vector<int>> combinationSum3(int k, int n) {
 		
 	vector<int> nums = {1,2,3,4,5,6,7,8,9};
 	vector<int> ds;
 	vector<vector<int> > ans;
 	help(0,nums,ans,ds,k,n);
 	return ans;
}


int main()
{

vvi ans = combinationSum3(3,7);
print2(ans);

 
return 0;
}
 