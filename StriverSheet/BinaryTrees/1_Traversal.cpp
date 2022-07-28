#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// level order insertion
TreeNode *insertListLevelOrder(vector<int> data)
{
    TreeNode *temp, *root, *node;
    queue<TreeNode *> q;
    int i = 0;
    root = new TreeNode(data[i]);
    q.push(root);
    i++;

    while (q.size() > 0 && i < data.size())
    {
        node = q.front();
        q.pop();
        // left
        if (data[i] != -1)
        {
            node->left = new TreeNode(data[i]);
            q.push(node->left);
        }
        i++;
        // right
        if (data[i] != -1)
        {
            node->right = new TreeNode(data[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void print_preorderTraversal(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        print_preorderTraversal(root->left);
        print_preorderTraversal(root->right);
    }
}

void print_inorderTraversal(TreeNode *root)
{
    if (root)
    {
        print_inorderTraversal(root->left);
        cout << root->val << " ";
        print_inorderTraversal(root->right);
    }
}
void print_postorderTraversal(TreeNode *root)
{
    if (root)
    {
        print_postorderTraversal(root->left);
        print_postorderTraversal(root->right);
        cout << root->val << " ";
    }
}

int main()
{

    vector<int> vec = {1, 2, 3, 4, 5};
    TreeNode *root;
    root = insertListLevelOrder(vec);
    print_preorderTraversal(root);
    cout << endl;
    print_inorderTraversal(root);
    cout << endl;
    print_postorderTraversal(root);
    cout << endl;

    return 0;
}