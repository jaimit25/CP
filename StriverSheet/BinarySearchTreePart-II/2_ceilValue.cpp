#include <bits/stdc++.h>
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

int findCeil(TreeNode *node, int x) {

  int ans = -1;
  while (node) {
    if (node->val == x)
      return node->val;

    if (x > node->val)
      node = node->left;
    else {
      ans = node->val;
      node = node->right;
    }
  }
  return ans;
}

int main() {

  TreeNode *root = new TreeNode(8);

  root->left = new TreeNode(3);
  root->right = new TreeNode(10);

  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(6);

  root->right->right = new TreeNode(14);

  root->left->right->left = new TreeNode(4);
  root->left->right->right = new TreeNode(7);

  root->right->right->left = new TreeNode(13);

  print_preorderTraversal(root);
  cout << endl;
  int key = 3;
  cout << " Ceil Value is : " << findCeil(root, key) << endl;

  return 0;
}