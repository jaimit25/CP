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

int floor_InBST(TreeNode *root, int X) {

  if (!root)
    return -1;

  stack<TreeNode *> stk;
  stk.push(root);
  int target = INT_MIN;

  while (!stk.empty()) {
    TreeNode *node = stk.top();
    stk.pop();

    if (node->val <= X && target < node->val) {
      target = node->val;
    }

    cout << node->val << " ";

    if (node->right)
      stk.push(node->right);

    if (node->left)
      stk.push(node->left);
  }

  cout << endl;
  if (target == INT_MIN)
    return -1;
  return target;
}

auto flooInBST(TreeNode *root, int X) -> int {

  int ans = INT_MIN;
  TreeNode *curr = root;
  while (curr) {

    if (curr->val == X)
      return X;

    if (curr->val < X) {
      ans = curr->val;
      curr = curr->right;

    } else
      curr = curr->left;
  }

  return ans;
}

int main() {

  TreeNode *root = NULL;
  root = new TreeNode(10);

  root->left = new TreeNode(5);
  root->right = new TreeNode(15);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(6);

  cout << floor_InBST(root, 14) << endl;

  return 0;
}