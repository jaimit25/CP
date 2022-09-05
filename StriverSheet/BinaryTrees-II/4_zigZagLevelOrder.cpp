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

void print_levelOrder(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {

    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode *temp = q.front();
      cout << temp->val << " ";
      q.pop();

      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {

  vector<vector<int>> result;
  if (root == NULL) {
    return result;
  }

  queue<TreeNode *> q;
  bool f = false;
  q.push(root);

  while (!q.empty()) {
    vector<int> v;
    int size = q.size();

    for (int i = 0; i < size; i++) {

      TreeNode *temp = q.front();
      q.pop();
      v.push_back(temp->val);

      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }

    if (f) {
      reverse(v.begin(), v.end());
    }
    f = !f;

    result.push_back(v);
    v.clear();
  }

  return result;
}

int main() {

  TreeNode *root = new TreeNode(3);

  root->left = new TreeNode(9);
  root->right = new TreeNode(20);

  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  print_levelOrder(root);
  cout<<endl;

  vector<vector<int>> ans = zigzagLevelOrder(root);
  for (auto it : ans) {
    for (auto i : it) {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}