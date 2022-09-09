#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node *insertListLevelOrder(vector<int> data) {
  Node *temp, *root, *node;
  queue<Node *> q;
  int i = 0;
  root = new Node(data[i]);
  q.push(root);
  i++;

  while (q.size() > 0 && i < data.size()) {
    node = q.front();
    q.pop();
    // left
    if (data[i] != -1) {
      node->left = new Node(data[i]);
      q.push(node->left);
    }
    i++;
    // right
    if (data[i] != -1) {
      node->right = new Node(data[i]);
      q.push(node->right);
    }
    i++;
  }
  return root;
}
void print_preorderTraversal(Node *root) {
  if (root) {
    cout << root->val << " ";
    print_preorderTraversal(root->left);
    print_preorderTraversal(root->right);
  }
}

void print_inorderTraversal(Node *root) {
  if (root) {
    print_inorderTraversal(root->left);
    cout << root->val << " ";
    print_inorderTraversal(root->right);
  }
}
void print_postorderTraversal(Node *root) {
  if (root) {
    print_postorderTraversal(root->left);
    print_postorderTraversal(root->right);
    cout << root->val << " ";
  }
}

Node *connect(Node *root) {
  if (!root)
    return NULL;
  map<int, vector<Node *>> mp;
  queue<Node *> q;
  q.push(root);

  int level = 0;
  vector<Node *> temp;

  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      Node *nd = q.front();
      q.pop();

      temp.push_back(nd);

      if (nd->left)
        q.push(nd->left);
      if (nd->right)
        q.push(nd->right);
    }
    mp[level] = temp;
    level++;
    temp.clear();
  }

  for (auto it : mp) {
    // mp.first : level
    // mp.second : vector<Node*>
    int sz = it.second.size();
    for (int i = 0; i < sz; i++) {
      if (i == sz - 1)
        it.second[i]->next = NULL;
      else {
        it.second[i]->next = it.second[i + 1];
      }
    }
  }
  return root;
}

int main() {

  Node *root = new Node(1);

  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);

  root->right->left = new Node(6);
  root->right->right = new Node(7);

  print_inorderTraversal(root);
  cout<<endl;
  
  root = connect(root);

  print_inorderTraversal(root);
  cout<<endl;

  return 0;
}