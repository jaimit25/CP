#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node *insertListLevelOrder(vector<int> data)
{
    Node *temp, *root, *node;
    queue<Node *> q;
    int i = 0;
    root = new Node(data[i]);
    q.push(root);
    i++;

    while (q.size() > 0 && i < data.size())
    {
        node = q.front();
        q.pop();
        // left
        if (data[i] != -1)
        {
            node->left = new Node(data[i]);
            q.push(node->left);
        }
        i++;
        // right
        if (data[i] != -1)
        {
            node->right = new Node(data[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}
void print_preorderTraversal(Node *root)
{
    if (root)
    {
        cout << root->val << " ";
        print_preorderTraversal(root->left);
        print_preorderTraversal(root->right);
    }
}

void print_inorderTraversal(Node *root)
{
    if (root)
    {
        print_inorderTraversal(root->left);
        cout << root->val << " ";
        print_inorderTraversal(root->right);
    }
}
void print_postorderTraversal(Node *root)
{
    if (root)
    {
        print_postorderTraversal(root->left);
        print_postorderTraversal(root->right);
        cout << root->val << " ";
    }
}

void rf(Node *node, int level, vector<int> &ans)
{
    if (node == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(node->val);
    }
    rf(node->left, level + 1, ans);
    rf(node->right, level + 1, ans);
}

// we will use simple pre-order traversal to see the right view
vector<int> leftView(Node *root)
{
    vector<int> ans;
    rf(root, 0, ans);
    return ans;
}

int main()
{
    Node *root;
    vector<int> v = {1, 2, 3};
    root = insertListLevelOrder(v);
    print_preorderTraversal(root);

    return 0;
}