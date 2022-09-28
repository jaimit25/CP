#include <bits/stdc++.h>
#include <queue>
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

int kthSmallest(TreeNode *root, int k) {

  priority_queue<int> q;
  stack<TreeNode *> s;
  TreeNode *curr = root;
  int cnt = k;

  while (curr != NULL || s.empty() == false) {

    while (curr != NULL) {
      s.push(curr);
      curr = curr->left;
    }

    curr = s.top();
    s.pop();
    cout << curr->val << " ";
    cnt--;
    if (cnt == 0)
      break;

    curr = curr->right;
  }

  if (!curr) {
    return -1;
  }
  return curr->val;
}

int main() {

  TreeNode *root = new TreeNode(5);

  root->left = new TreeNode(3);
  root->right = new TreeNode(6);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);

  root->left->left->left = new TreeNode(1);

  print_preorderTraversal(root);
  cout << endl;
  cout << kthSmallest(root, 3) << endl;

  return 0;
}
