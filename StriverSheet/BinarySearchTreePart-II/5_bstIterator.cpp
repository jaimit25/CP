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

void print_preorderTraversal(TreeNode *root) {
  if (root) {
    cout << root->val << " ";
    print_preorderTraversal(root->left);
    print_preorderTraversal(root->right);
  }
}

class BST_Iterator {

public:
  stack<TreeNode *> st;

  BST_Iterator(TreeNode *root) { pushAll(root); }
  void pushAll(TreeNode *root) {
    while (root != NULL) {
      st.push(root);
      root = root->left;
    }
  }
  bool hasNext() { return !st.empty(); }
  int next() {
    TreeNode *temp = st.top();
    st.pop();
    pushAll(temp->right);
    return temp->val;
  }
};

int main() { return 0; }