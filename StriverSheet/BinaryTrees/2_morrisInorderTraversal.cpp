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

TreeNode *getpredecessor(TreeNode *p)
{
    // node p and its right child  is not NULL
    while (p && p->right)
    {
        p = p->right;
    }
    return p;
}

// Morris inorder traversal
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;

    TreeNode *curr = root;
    while (curr != NULL)
    {

        if (curr->left == nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // we need inorder predecessor
            TreeNode *p = curr->left;                    // p : previous node
            while (p->right != NULL && p->right != curr) // if there exist a right node and it does not point to itself
            {
                p = p->right;
            }

            if (p->right == NULL)
            {
                // make thread or link
                p->right = curr;
                curr = curr->left;
            }
            else
            {
                // p node has a link , break link or thread
                p->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main()
{
    TreeNode *root;
    vector<int> v = {1, 2, 3, 4, 5};
    root = insertListLevelOrder(v);
    print_inorderTraversal(root);
    cout << endl;
    return 0;
}