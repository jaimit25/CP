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

TreeNode *Construct(vector<int> preorder, int preStart, int preEnd,
                    vector<int> inorder, int inStart, int inEnd,
                    map<int, int> mp) {

  // baseCase
  if (preStart > preEnd || inStart > inEnd)
    return NULL;

  TreeNode *root = new TreeNode(preorder[preStart]);
  //getting the index of where the current root/subRoot is located in the inorder vector
  int inRoot = mp[root->val];
  int numsLeft = inRoot - inStart; //no of nodes on the left side of the root in the in-order vector



  // calling this function again so that for current node we can develope the
  // left and right side elements
  root->left = Construct(preorder, preStart + 1, preStart + numsLeft, inorder,
  inStart, inRoot - 1, mp);
  root->right = Construct(preorder, preStart + numsLeft + 1, preEnd, inorder, 
  inRoot + 1, inEnd, mp);

  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

  int preStart = 0, preEnd = preorder.size() - 1, inStart = 0,
      inEnd = inorder.size() - 1;

  map<int, int> mp;

  // putting inorder traversal into the hashMap
  for (int i = 0; i < inorder.size(); i++) {
    mp[inorder[i]] = i;
  }

  return Construct(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}

int main() {

  vector<int> pre = {40, 20, 50, 10, 60, 30};
  vector<int> ino = {10, 20, 40, 50, 30, 60};

  TreeNode *root = buildTree(pre, ino);
  print_inorderTraversal(root);

  return 0;
}