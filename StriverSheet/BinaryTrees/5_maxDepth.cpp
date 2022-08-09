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

int maxDepth(TreeNode *node)
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
int widthOfBinaryTree(TreeNode *root)
{
    // int maxD = maxDepth(root);
    // if (maxD == 0)
    //     return 1;
    // else if (maxD == -1)
    //     return 0;
    // else
    // {
    //     return pow(2, maxD);
    // }

    if (!root)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root,
            0});
    while (!q.empty())
    {
        int size = q.size();
        int curMin = q.front().second;
        int leftMost, rightMost;
        for (int i = 0; i < size; i++)
        {
            int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
            TreeNode *temp = q.front().first;
            q.pop();
            if (i == 0)
                leftMost = cur_id;
            if (i == size - 1)
                rightMost = cur_id;
            if (temp->left)
                q.push({temp->left,
                        cur_id * 2 + 1});
            if (temp->right)
                q.push({temp->right,
                        cur_id * 2 + 2});
        }
        ans = max(ans, rightMost - leftMost + 1);
    }
    return ans;
}

int main()
{

    TreeNode *root;
    vector<int> v = {1, 2, 3, 4, 5};
    root = insertListLevelOrder(v);
    print_preorderTraversal(root);
    cout << endl
         << widthOfBinaryTree(root) << endl;

    return 0;
}