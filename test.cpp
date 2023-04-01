#include<bits/stdc++.h>
#define ll long long int
#define F first 
#define S              second
#define pb             push_back
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vs             vector<string>
#define vvi            vector<vector<int>>
#define vvs            vector<vector<string>>
#define vvc            vector<vector<char>>
#define vvll            vector<vector<long long>>
#define svi            set<vector<int>> 
#define si             set <int>





using namespace std;
 
template<class T>
void print(T &a){
    for(auto it : a){
        cout<<it<<" ";
    }
    cout<<endl;
}

template<class T>
void print2(T &a){
    for(auto it : a){
        for(auto i : it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
}

class Node{
    int val;
    Node*next;
    Node(int data){
        val = data;
        next = NULL;
    }
};


class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

void preT(TreeNode* root){
    if(root){
        cout<<root->data<<" ";
        preT(root->left);
        preT(root->right);
    }
}

void inT(TreeNode* root){
    if(root){
        inT(root->left);
        cout<<root->data<<" ";
        inT(root->right);
    }
}

void postT(TreeNode* root){
    if(root){
        postT(root->left);
        postT(root->right);
        cout<<root->data<<" ";
    }
}

void levelT(TreeNode *root){

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        cout<<temp -> data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}

TreeNode* insert(vi& nodes){
    if(nodes.size() == 0) {
        return NULL;
    }
    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode*>  q;
    q.push(root);

    int i = 1 ;
    while(i < nodes.size() && !q.empty()){
        
        TreeNode *nd = q.front();
        q.pop();
        
        if(nodes[i] != -1){
             nd->left = new TreeNode(nodes[i]);
             q.push(nd->left);
        }
        i++;
           
        if(nodes[i] != -1){
            nd->right = new TreeNode(nodes[i]);
            q.push(nd->right);
          }
          i++;
      }
        return root;
}

TreeNode * pred(TreeNode * root){
    TreeNode * nd = root;
    while(nd->right != NULL && nd){
        nd = nd->right;
    }
    return nd;
}

void m_inorder(TreeNode * root1){

    TreeNode* head = root1;

    while(head){

        if(!head->left){
            cout<<head->data<<" ";
            head = head -> right; // right will always exist
        }
        else{
            // left exist so just make link and go left
            //     - Possiblity
            //           - link already Exist 
            //           - link do not Exist


            //Try to get inorder-pred [if link exist and do not exist]
            TreeNode * nd = head->left;
            while(nd->right != NULL && nd->right != head){
                nd = nd->right;
            }
            
            //create link and go left
            if(nd->right == NULL){
                nd->right = head;
                head = head->left;
            }

            //link already exist [break]
            if(nd->right == head){
                nd->right = NULL;
                cout<<head->data<<" ";
                head = head->right;
            }
            
        }

    }

 }




void solve(){
    vi nodes = {1,2,3,4,5,-1,-1,-1,-1,-1,6,};
    TreeNode* root1 = insert(nodes);
    m_inorder(root1);

    return ;
}
 
int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

solve();
 
 
return 0;
}
 