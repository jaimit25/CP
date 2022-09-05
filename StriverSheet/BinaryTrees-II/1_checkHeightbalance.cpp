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

// int getHeight(TreeNode *root)
// {

//     if (!root)
//         return 0;
//     int left = getHeight(root->left);
//     int right = getHeight(root->right);
//     return max(left, right) + 1;
// }

// bool CheckBalance(TreeNode *root)
// {

//     int lh = getHeight(root->left);
//     int rh = getHeight(root->right);
//     cout << "left and right height\(" << root->val << "\) : " << lh << " " << rh << endl;
//     if (abs(lh - rh) > 1)
//         return false;
//     return true;
// }

// //o(n2);
// bool isBalanced(TreeNode *root)
// {

//     bool result;

//     // base cases :
//     // Leaf Node
//     if (!root)
//         return true;
//     // Current Node is not Balanced
//     if (!CheckBalance(root))
//         return false;

//     bool res_l = isBalanced(root->left);
//     bool res_r = isBalanced(root->right);

//     return res_l && res_r;
// }


//optimized approach o(n)
int dfs(TreeNode*);
bool isBalanced(TreeNode *root)
{
    if(dfs(root) == -1 )    return false;
    return true;
}
//height function which will also tell if tree is balanced or not
//if we find left and right heigth is not same then we return -1 to the root node
int dfs(TreeNode* root){
    //dfs - preorder traversal

    if(root == NULL) return 0;

    int lh = dfs(root->left);
    int rh = dfs(root->right);
    if(lh == -1 || rh == -1) return -1;

    if (abs(lh - rh) > 1)  
            return -1;
    
    return max(lh,rh)+1;
}

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    // root->right->right->right = new TreeNode(17); // making tree un-balance

    if (isBalanced(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}