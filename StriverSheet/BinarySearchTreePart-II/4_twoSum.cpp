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
class BSTIterator {
private:
  stack<TreeNode *> st;
  bool reverse = false;
  void push(TreeNode *root) {
    while (root != nullptr) {
      st.push(root);
      root = !reverse ? root->left : root->right;
    }
  }

public:
  BSTIterator(TreeNode *root, bool reverse = false) : reverse(reverse) {
    push(root);
  }
  int next() {
    TreeNode *top = st.top();
    st.pop();
    push(!reverse ? top->right : top->left);
    return top->val;
  }
};

class Solution {
public:
  bool findTarget(TreeNode *root, int k) {
    BSTIterator leftItr(root), rightItr(root, true);
    int left = leftItr.next(), right = rightItr.next();
    while (left < right) {
      if (left + right == k)
        return true;
      if (left + right < k)
        left = leftItr.next();
      else
        right = rightItr.next();
    }
    return false;
  }
};

 int main(){


  

  return 0;
 }