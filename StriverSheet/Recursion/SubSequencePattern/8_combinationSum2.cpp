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

 
 void print2(vvi &a){
 	for(auto it : a){
 		for(auto i : it)
 		{
 			cout<<i<<" ";
 		}
 		cout<<endl;
 	}
 }


//Approach 1
//void help(int i, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds ){
//     	int n = arr.size();

// 	if(i == n ){
// 		if(target == 0) ans.push_back(ds);
// 		return ; 
// 	}

// 	if(arr[i] <= target){
// 		ds.push_back(arr[i]);
// 		help(i+1,target-arr[i],arr,ans,ds);
// 		ds.pop_back();
// 	}
// 	help(i+1,target,arr,ans,ds);
    
// 	return ; 
// }

// vector<vector<int>> combinationSum2(vector<int>& candidates, int target)    {
//        vector<vector<int  >> ans; 
//         vector<int > ds;
//         help(0,target,candidates,ans,ds);
//         set<vector<int>> st;
//         for(auto it: ans){
//           sort(it.begin(),it.end());
//           st.insert(it);
//         }
//           ans.clear();
//         for(auto it: st){        
//             ans.push_back(it);
//         }
//         return ans;
    
// } 


//Approach 2
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue; //skip duplicate element to avoid repeating same sequence -  to avoid use of set data structure from approach 1
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)    {
      sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
    
}





 int main()
 {
 
 vi a = {2,3,6,7};
 vvi ans = combinationSum2(a,7);
 print2(ans);
 
  
  
 return 0;
 }
   