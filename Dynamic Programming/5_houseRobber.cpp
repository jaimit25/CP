#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  int findMax(int start, int end, vector<int> &nums) {
    int prev = nums[start];
    int prev2 = 0;
    for (int i = start + 1; i < end; i++) {
      int pick = nums[i];
      if (i > 1)
        pick += prev2;
      int notPick = prev;
      int curr = max(pick, notPick);
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }

public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    if (n == 2)
      return max(nums[0], nums[1]);
    int ans1 = findMax(0, n - 1, nums);
    int ans2 = findMax(1, n, nums);
    return max(ans1, ans2);
  }
};

int main() {

  vector<int> v = {2, 3, 2};
  Solution obj;
  cout << obj.rob(v) << endl;

  return 0;
}