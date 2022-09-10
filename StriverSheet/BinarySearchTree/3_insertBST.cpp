#include <bits/stdc++.h>
using namespace std;
// InComplete
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

// int getHeight(TreeNode *root) {

//   int left, right;
//   if (root == NULL) {
//     return 0;
//   }
//   left = getHeight(root->left);
//   right = getHeight(root->right);

//   return max(left, right) + 1;
// }

// auto bFac(TreeNode *root) -> int {

//   if (!root)
//     return 0;
//   int left = getHeight(root->left);
//   int right = getHeight(root->right);

//   return left - right;
// }

// bool isBalance(TreeNode *root) {
//   int fac = 0;
//   int leftHeight = getHeight(root->left);
//   int rightHeight = getHeight(root->right);
//   fac = abs(leftHeight - rightHeight);
//   if (fac == 0)
//     return true;
//   else if (fac > 1)
//     return false;
//   else
//     return true;
// }

// TreeNode *LL(TreeNode *root) {

//   TreeNode *r = root;
//   TreeNode *r_l = r->left;

//   TreeNode *r_lr = NULL;

//   if (r_l->right)
//     r_lr = r_l->right;

//   // R,RL,RLL
//   r->left = r_lr;
//   r_l->right = r;

//   return r_l;
// }

// TreeNode *RR(TreeNode *root) {

//   TreeNode *r = root;
//   TreeNode *rr = root->right;
//   TreeNode *rrl = root->right->left;

//   r->right = rrl;
//   rr->left = r;
//   return rr;
// }

// TreeNode *LR(TreeNode *root) {

//   TreeNode *l, *lr, *lrl, *lrr;
//   l = root->left;
//   lr = l->right;
//   lrl = lr->left;
//   lrr = lr->right;

//   lr->left = l;
//   lr->right = root;

//   l->right = lrl;
//   root->left = lrr;

//   return lr;
// }

// TreeNode *RL(TreeNode *root) {

//   TreeNode *r, *rl, *rll, *rlr;

//   r = root->right;
//   rl = r->left;
//   rll = rl->left;
//   rlr = rl->right;

//   r->left = rlr;
//   root->right = rll;

//   rl->left = root;
//   rl->right = r;

//   return rl;
// }

// // Iterative Insertion BST
// TreeNode *Insert(TreeNode *root, int key) {
//   if (root == NULL) {
//     root = new TreeNode(key);
//     root->left = root->right = NULL;
//     return root;
//   }

//   TreeNode *p, *r;
//   TreeNode *temp;
//   p = root;
//   while (p) {
//     r = p;
//     if (p->val == key)
//       return root;
//     else if (p->val > key)
//       p = p->left;
//     else
//       p = p->right;
//   }
//   temp = new TreeNode(key);
//   temp->left = temp->right = NULL;

//   if (r->val > key)
//     r->left = temp;
//   else
//     r->right = temp;

//   return root;
// }

TreeNode *newNode(int data) {
  TreeNode *node = new TreeNode();
  node->val = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

TreeNode *sortedArrayToBS(vector<int> arr, int start, int end) {
  if (start > end)
    return NULL;

  /* Get the middle element and make it root */
  int mid = (start + end) / 2;
  TreeNode *root = newNode(arr[mid]);

  /* Recursively construct the left subtree
  and make it left child of root */
  root->left = sortedArrayToBS(arr, start, mid - 1);

  /* Recursively construct the right subtree
  and make it right child of root */
  root->right = sortedArrayToBS(arr, mid + 1, end);

  return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
  TreeNode *root = NULL;
  root = sortedArrayToBS(nums, 0, nums.size() - 1);
  return root;
}

int main() {
  TreeNode *root = NULL;
  // Unbalanced binary tree - LL Rotation
  // root = new TreeNode(20);
  // root->left = new TreeNode(10);
  // root->left->left = new TreeNode(5);

  // print_inorderTraversal(root);
  // cout << endl;

  // root = LL(root);

  // print_inorderTraversal(root);
  // cout << endl;
  // cout << bFac(root->left->left) << endl;

  return 0;
}