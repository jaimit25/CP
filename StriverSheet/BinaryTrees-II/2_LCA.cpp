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

void print_preorderTraversal(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        print_preorderTraversal(root->left);
        print_preorderTraversal(root->right);
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q) {
            return root;
        }

    queue<TreeNode *> qq;
    map<TreeNode *, TreeNode *> mp;

    qq.push(root);
    TreeNode *ans, *curr;

    while (!qq.empty())
    {
        curr = qq.front();
        qq.pop();

        // mp {
        // child1 : parent1,
        // child2 : parent2
        //}

        // Left and Right node push into queue
        if (curr->left)
        {
            qq.push(curr->left);
            mp[curr->left] = curr;
        }
        if (curr->right)
        {
            qq.push(curr->right);
            mp[curr->right] = curr;
        }
    }


    if (p)
        ans = mp[p];
    else if(q)
        ans = mp[q];
    if(ans->left != p && ans->right != q) ans = p;

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // It should print 2
    cout << lowestCommonAncestor(root, root->left->left, root->left->right)->val << endl;

    return 0;
}