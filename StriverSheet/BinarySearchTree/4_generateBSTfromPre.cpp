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

TreeNode *build(vector<int> &preorder, int &ptr, int bound) {
    // we return NULL in 2 cases
    //  1. If nodes are finished in preorder vector i.e ptr > size of
    //  vector
    //  2. If preorder[ptr] > given bound, then it wont be part of that node
    //  subtrees
    // and have to move up to parent nodes.
    if (ptr == preorder.size() || preorder[ptr] > bound)
      return NULL;

    // preorder is root->left->right
    TreeNode *root = new TreeNode(preorder[ptr++]);
    root->left = build(preorder, ptr, root->val);
    root->right = build(preorder, ptr, bound);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder) {
  // have a universal pointer for traversing the preorder vector
  int ptr = 0;
  // build the tree and return its root
  return build(preorder, ptr, INT_MAX);
}

int main() {
  vector<int> pre = {8, 5, 1, 7, 10, 12};
  TreeNode *root = bstFromPreorder(pre);


  print_preorderTraversal(root);
  cout<<endl;

  return 0;
}