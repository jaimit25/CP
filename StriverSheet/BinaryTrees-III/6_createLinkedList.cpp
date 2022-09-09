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

void flatten(TreeNode *root) {

  if (!root)
    return;

  stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode *curr = st.top();
    cout << curr->val << " ";
    st.pop();

    if (curr->right)
      st.push(curr->right);

    if (curr->left)
      st.push(curr->left);

    if (!st.empty()) // we check this so that we dont asign leaf node right to
                     // stack top node
      curr->right = st.top();

    curr->left = NULL;
  }
}

int main() {

  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->right = new TreeNode(5);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);

  root->right->right = new TreeNode(6);

  //   print_preorderTraversal(root);
  flatten(root);

  return 0;
}