#include <bits/stdc++.h> 
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0] ; 
    int prev2 = 0;
    int cur = 0 ; 
    
    
    for(int i = 0 ; i < n ; i++){
      int tk = nums[i];
      if(i > 1) tk += prev2;       
      int ntk = 0 + prev;
      int cur = max(tk,ntk);
      prev2 = prev;
      prev = cur;        
    }
    return prev;
}

int main(){

	vector<int > v =  {2,3,2};
	cout<< maximumNonAdjacentSum(v)<<endl;

	return 0 ; 

}