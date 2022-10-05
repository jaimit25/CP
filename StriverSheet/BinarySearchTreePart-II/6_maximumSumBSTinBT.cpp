#include <bits/stdc++.h>
#include <climits>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *insertListLevelOrder(vector<int> data) {
  TreeNode *temp, *root, *node;
  queue<TreeNode *> q;
  int i = 0;
  root = new TreeNode(data[i]);
  q.push(root);
  i++;

  while (q.size() > 0 && i < data.size()) {
    node = q.front();
    q.pop();
    // left
    if (data[i] != -1) {
      node->left = new TreeNode(data[i]);
      q.push(node->left);
    }
    i++;
    // right
    if (data[i] != -1) {
      node->right = new TreeNode(data[i]);
      q.push(node->right);
    }
    i++;
  }
  return root;
}
void print_preorderTraversal(TreeNode *root) {
  if (root) {
    cout << root->val << " ";
    print_preorderTraversal(root->left);
    print_preorderTraversal(root->right);
  }
}

void print_inorderTraversal(TreeNode *root) {
  if (root) {
    print_inorderTraversal(root->left);
    cout << root->val << " ";
    print_inorderTraversal(root->right);
  }
}
void print_postorderTraversal(TreeNode *root) {
  if (root) {
    print_postorderTraversal(root->left);
    print_postorderTraversal(root->right);
    cout << root->val << " ";
  }
}

int helper(TreeNode *root, TreeNode *mainRoot, int &maxm, int minVal,
           int maxVal) {

  if (!root)
    return 0;
  int left = 0, right = 0;

  if (root) {
    left = helper(root->left, mainRoot, maxm, minVal, root->val);
    right = helper(root->right, mainRoot, maxm, root->val, maxVal);
  }

  if (root == mainRoot) {
    if (left < 0 && right < 0)
      return 0;
    return maxm;
  }

//   if (root->val <= minVal || root->val >= maxVal)
    maxm = max(maxm, left + right + root->val);

  if (left + right + root->val < 0)
    return 0;
  return left + right + root->val;
}

int maxSumBST(TreeNode *root) {
  int maxm = 0;
  int ans = helper(root, root, maxm, INT_MIN, INT_MAX);
  return ans;
}

int main() {

  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(4);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(5);

  root->right->right->left = new TreeNode(4);
  root->right->right->right = new TreeNode(6);

  cout << maxSumBST(root) << endl;

  return 0;
}