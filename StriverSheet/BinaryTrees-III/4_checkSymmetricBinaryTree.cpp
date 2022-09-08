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

bool Compare(TreeNode *left, TreeNode *right) {
  // left child and right child are both null, return true
  if (left == NULL && right == NULL)
    return true;
  // one of the left child is null, another one is not null, return false
  else if (left == NULL && right != NULL)
    return false;
  else if (left != NULL && right == NULL)
    return false;
  // both of the child are not null, val is not equal
  else if (left->val != right->val)
    return false;

  // Compare the outside of the treenode - getting the left and right side result
  bool outside = Compare(left->left, right->right);
  // Compare the inside of the treenode
  bool inside = Compare(left->right, right->left);

  return outside && inside;
}

bool isSymmetric(TreeNode *root) {
  if (root == NULL)
    return true;
  else
    return Compare(root->left, root->right);
}

int main() {
	
TreeNode *root = new TreeNode(1);

root->left = new TreeNode(2);
root->left = new TreeNode(2);

root->left->left = new TreeNode(3);
root->left->right = new TreeNode(4);

root->right->left = new TreeNode(4);
root->right->right = new TreeNode(3);

if(isSymmetric(root)) cout<<"Symmetric"<<endl;
else cout<<"Not Symmetric"<<endl;

  return 0;
}