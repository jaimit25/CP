#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vvll vector<vector<long long>>
#define svi set<vector<int>>
#define si set<int>

using namespace std;

template <class T> void print(T &a) {
  for (auto it : a) {
    cout << it << " ";
  }
  cout << endl;
}

template <class T> void print2(T &a) {
  for (auto it : a) {
    for (auto i : it) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int getMedian(vi &temps) {
  int n = temps.size();
  if (n % 2 == 0) {
    return temps[n / 2] + temps[n / 2 + 1];
  }
  return temps[(n / 2)];
}

// Question 1
//  int passThePillow(int n, int time) {

//   int cnt = 0;

//     cnt = -1;

//     while (cnt < time) {

//       for (int i = 1; i <= n; i++) {
//         cnt++;
//         if (cnt == time)
//           return i;
//       }

//       for (int i = n - 1; i >= 2; i--) {
//         cnt++;
//         if (cnt == time)
//           return i;
//       }
//     }
//   return -1;
// }

// Question 2
//  class TreeNode {
//    public :
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//      right(right) {}
//  };

// void printt(TreeNode* head){
//     if(head){
//         cout<<head->val<<" ";
//         printt(head->left);
//         printt(head->right);
//     }
// }

// long long kthLargestLevelSum(TreeNode* root, int k) {
//          if(root == NULL) return -1;
//         TreeNode* head = root;
//         queue<TreeNode*> q;
//         q.push(head);
//        vector<long long int> lvls;

//        long long int mxm = 0;

//         while(!q.empty()){
//           int sz = q.size();
//          long long int sum = 0 ;
//           for(int i = 0 ; i < sz;i++){
//             TreeNode* temp = q.front();
//             q.pop();
//             sum += temp->val;
//             if(temp->left) q.push(temp->left);
//             if(temp->right) q.push(temp->right);
//           }

//           lvls.push_back(sum);

//         }
//         sort(lvls.begin(),lvls.end());
//         if(lvls.size() < k) return -1;

//         return lvls[lvls.size()-k];

// }

// void help(vector<vector<int>> &types, int ind, int &target,
//           long long int &cnt,vector<vector<int>> &dp) {

//   if (target == 0) {
//     cnt = cnt + 1;
//     return;
//   }

//   if (target < 0 || ind >= types.size())
//     return;
    

//   if (target > 0 && types[ind][0] > 0) {

//     target = target - types[ind][1];
//     types[ind][0]--;

//     help(types, ind, target, cnt,dp);

//     target = target + types[ind][1];
//     types[ind][0]++;
//   }
//   help(types, ind + 1, target, cnt,dp);
// }

// int waysToReachTarget(int target, vector<vector<int>> &types) {
//   long long int count = 0;
//   vvi dp(types.size()+1,vector<int>(types.size()+1,-1));
//   long long int mod = (1e9 + 7);

//   help(types, 0, target, count,dp);

//   // return count % mod;
//   return count;
// }

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // int ans = passThePillow(3,2);
  // cout << ans << endl;

  // TreeNode* head = new TreeNode(5);
  // head->left = new TreeNode(8);
  // head->right = new TreeNode(9);

  // head->left->left = new TreeNode(2);
  // head->left->right = new TreeNode(1);

  // head->right->left = new TreeNode(3);
  // head->right->right = new TreeNode(7);

  // head->left->left->left = new TreeNode(4);
  // head->left->left->right = new TreeNode(6);

  // // printt(head);

  // cout<< kthLargestLevelSum(head,2)<<endl;



  // vvi a = {{50,1},{50,2},{50,5}};
  // int target = 5;

  // vvi a = {{6, 1}, {3, 2}, {2, 3}};
  // int target = 6;

  // cout << waysToReachTarget(target, a);

  return 0;
}
