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
 
void helper(string s , int i ,int n , int open , int close,vector<string> &ans){

	if(i == 2*n) {
		ans.push_back(s);
		return;
	}

	if(open < n){
		helper(s+'(' , i+1 , n , open+1,close, ans);
	}

	if(close < open and i != 0){
		helper(s+')' , i+1 , n , open,close+1, ans);
	}

}

vector<string> generateParenthesis(int n) {

vector<string> ans ; 
string s = "";

helper(s,0,n,0,0,ans);

return ans;
}


void print(vector<string> a){
	for(auto it  :a){
		cout<<it<<endl;
	}
	cout<<endl;
}

int main()
{


 
vector<string >  ans = generateParenthesis(3);
print(ans);
return 0;
}
 