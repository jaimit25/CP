#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n = nums.size();
    long long int ans = nums[0],r_ans = nums[n-1];
    long long int c = nums[0],r_c = nums[n-1];

     
    for(int i = 1 ; i < n ; i++){   

        if(c==0){
           
            c = 1;
        }
        if(r_c == 0){
             r_c = 1;
        }

        c = c*nums[i];
        r_c = r_c*nums[n-i-1];

        r_ans = max(r_ans,r_c);
        ans = max(ans,c);
    }

     return max(ans,r_ans);   
    }
};
int main(){


}