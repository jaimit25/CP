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

// bool valid(TreeNode *root, TreeNode *parent, int bound, int isRight,
//            bool main_root) {

//   if (!root)
//     return true;

//   if (!main_root)
//     if (parent->val == root->val)
//       return false;

//   //   cout << parent->val << " " << root->val << " " << bound << " ";

//   if (isRight) {
//     //     cout << "Right side" << endl;
//     if (parent->val > root->val) {
//       //       cout << " False"
//       //            << " ";
//       return false;
//     }
//   }
//   //   if (isRight)
//   //     cout << " (Right)" << endl << endl;
//   //   else
//   //     cout << " (Left)" << endl << endl;

//   if (bound < root->val)
//     return false;

//   bool left = valid(root->left, root, root->val, 0, false);
//   bool right = valid(root->right, root, bound, 1, false);

//   return left && right;
// }

// bool isValidBST(TreeNode *root) {
//   int bound = INT_MAX;
//   return valid(root, root, bound, 1, true);
// }


bool isValidBS(TreeNode *root, long minVal, long maxVal) {
  if (root == NULL)
    return true;
  if (root->val <= minVal || root->val >= maxVal)
    return false;
  return isValidBS(root->left, minVal, root->val) &&
         isValidBS(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode *root) { return isValidBS(root, LONG_MIN, LONG_MAX); }

int main() {
  //     TreeNode *root = new TreeNode(2);
  //     root->left = new TreeNode(1);
  //     root->right = new TreeNode(3);

  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);

  //   TreeNode *root2 = new TreeNode(5);
  //   root2->left = new TreeNode(1);
  //   root2->right = new TreeNode(4);
  //   root2->right->left = new TreeNode(3);
  //   root2->right->right = new TreeNode(6);

  print_preorderTraversal(root);
  cout << endl;

  //   print_preorderTraversal(root2);
  //   cout << endl;

  if (isValidBST(root)) {
    cout << "true" << endl;
  } else
    cout << "false" << endl;

  return 0;
}