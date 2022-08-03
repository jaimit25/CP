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

int maxDepth(Node *node)
{
    if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

// vector<int> bottomView(Node *root)
// {
//     vector<int> ans;
//     if (root == NULL)
//         return ans;
//     map<int, int> mpp;
//     queue<pair<Node *, int>> q;
//     q.push({root, 0});
//     while (!q.empty())
//     {
//         auto it = q.front();
//         q.pop();
//         Node *node = it.first;
//         int line = it.second;
//         mpp[line] = node->val;

//         if (node->left != NULL)
//         {
//             q.push({node->left, line - 1});
//         }
//         if (node->right != NULL)
//         {
//             q.push({node->right, line + 1});
//         }
//     }

//     for (auto it : mpp)
//     {
//         ans.push_back(it.second);
//     }
//     return ans;
// }

vector<int> bottomView(Node *root)
{
   vector<int> ans;
    if (root == NULL)
        return ans;

    queue<pair<Node *, int>> q;
    map<int, int> map;
    q.push({root, 0});

    while (!q.empty())
    {
        Node *temp = q.front().first;
        int level = q.front().second;
        map[level] = temp->val;
        q.pop();

        if (temp->left)
            q.push({temp->left, level - 1});
        if (temp->right)
            q.push({temp->right, level + 1});
    }
    for (auto it : map)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    vector<int> a = {10, 20, 30};
    root = insertListLevelOrder(a);
    // setting up tree
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    // question related set up
    a = bottomView(root);
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}