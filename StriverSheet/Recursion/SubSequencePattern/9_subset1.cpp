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

void help(int i, vector<int> &arr, vector<int> &sum , int sm){
	if(i == arr.size()){
		sum.push_back(sm);
		return;
	}

	help(i+1,arr,sum,sm+arr[i]);
	help(i+1,arr,sum,sm);
}


vector<int> subsetSums(vector<int> arr, int N)
{
	vector<int>  ans;
	help(0,arr,ans,0);
	reverse(ans.begin(),ans.end());
	return ans;
}


 
int main()
{

vi a = {5, 2, 1};
vi ans = subsetSums(a,a.size());
print(ans);

return 0;
}
 