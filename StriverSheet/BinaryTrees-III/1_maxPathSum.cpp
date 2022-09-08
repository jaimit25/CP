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

int helper(TreeNode *root, int &maxS) {
  if (!root)
    return 0;
  int left = max(0, helper(root->left, maxS));
  int right = max(0, helper(root->right, maxS));
  maxS = max(maxS, left + root->val + right);
  return max(left, right) + root->val;
}

int maxPathSum(TreeNode *root) {
  int maxS = INT_MIN;
  helper(root, maxS);
  return maxS;
}

int main() {

  TreeNode *root = new TreeNode(-10);

  root->left = new TreeNode(9);
  root->right = new TreeNode(20);

  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  print_preorderTraversal(root);
  cout << endl;
  cout << maxPathSum(root) << endl;

  return 0;
}