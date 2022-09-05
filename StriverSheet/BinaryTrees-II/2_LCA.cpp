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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {


    //base case
  if (root == NULL || p == root || q == root) {
    return root;
  }

    //calling for left and right value it will have either the p or q node value or the Null value
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);


   // carry forward Node 
  if (left == NULL)
    return right;
  if (right == NULL)
    return left;
  else // got both the node p and q so this condn will work when there is a common node which is this node itself
    return root;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  // print_preorderTraversal(root);

  // It should print 2
  cout << lowestCommonAncestor(root, root->left->left, root->left->right)->val
       << endl;

  return 0;
}