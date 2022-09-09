#include <bits/stdc++.h>
//By striver  
using namespace std;

struct TreeNode {
  int data;
  struct TreeNode *left, *right;
};

void reorder(TreeNode *root) {
  if (root == NULL)
    return;
  int child = 0;
  if (root->left) {
    child += root->left->data;
  }
  if (root->right) {
    child += root->right->data;
  }

  if (child < root->data) {
    if (root->left)
      root->left->data = root->data;
    else if (root->right)
      root->right->data = root->data;
  }

  reorder(root->left);
  reorder(root->right);

  int tot = 0;
  if (root->left)
    tot += root->left->data;
  if (root->right)
    tot += root->right->data;
  if (root->left || root->right)
    root->data = tot;
}
void changeTree(TreeNode *root) { reorder(root); }

struct TreeNode *newTreeNode(int data) {
  struct TreeNode *TreeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  TreeNode->data = data;
  TreeNode->left = NULL;
  TreeNode->right = NULL;

  return (TreeNode);
}

int main() {

  struct TreeNode *root = newTreeNode(2);
  root->left = newTreeNode(35);
  root->left->left = newTreeNode(2);
  root->left->right = newTreeNode(3);
  root->right = newTreeNode(10);
  root->right->left = newTreeNode(5);
  root->right->right = newTreeNode(2);

  changeTree(root);

  return 0;
}