
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int sz = nums.size();
    if(sz==0 ||sz == 1) return sz;
        
    int i = 0;
        
        
    for(int j = 1 ;j < sz;j++){
        if(nums[i] != nums[j])
        {
            i++;
           swap(nums[i],nums[j]); 
        } 
    }

        return i+1;

    }
};

auto main() -> int {
	return 0 ;
}