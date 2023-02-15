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
#define bgn .begin()

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


void help(int i, int target, vector<int> &arr, vector<vector<int>> &ans , vector<int> &ds ){
	int n = arr.size();

	if(i == n ){
		if(target == 0) ans.push_back(ds);
		return ; 
	}

	if(arr[i] <= target){
		ds.push_back(arr[i]);
		help(i,target-arr[i],arr,ans,ds);
		ds.pop_back();
	}
	help(i+1,target,arr,ans,ds);
	return ; 
}


 vector<vector<int>> combinationSum(vector<int>& candidates, int target)     {
        vector<vector<int  >> ans; 
        vector<int > ds;
        help(0,target,candidates,ans,ds);
        return ans;
  }

 
int main()
{

 vi a = {2,3,6,7};
 vvi ans = combinationSum(a,7);
 print2(ans);
 
return 0;
}
 