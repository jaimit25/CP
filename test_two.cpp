#include<bits/stdc++.h>

using namespace std;

class TreeNode{
	public: 
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data){
		val = data;
		left = NULL;
		right = NULL;
	}
};

class Node{

	public : 
	int data;
	Node *next;
	Node(int val)
	{
		data=val;
		next = NULL;
	}
};

void print_preorder(TreeNode * root){
	if(root){
		cout<<root->val<<" ";
		print_preorder(root->left);
		print_preorder(root->right);
	}
}


void print_inorder(TreeNode * root){
	if(root){
		print_inorder(root->left);
		cout<<root->val<<" ";
		print_inorder(root->right);
	}
}

void print_postorder(TreeNode * root){
	if(root){
		print_postorder(root->left);
		print_postorder(root->right);
		cout<<root->val<<" ";
	}
}

void print_levelorder(TreeNode * root)
{
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		int sz = q.size();
		for(int i = 0 ; i < sz ; i ++){
			TreeNode *top =  q.front();
			q.pop();
			cout<<top->val<<" ";
			if(top->left) q.push(top->left);
			if(top->right) q.push(top->right);
		}
	}

}

void printLL(Node * root){
	Node * head = root;
	while(head){
		cout<<head->data<< " "; 
		head = head->next;
	}
}

void print_subsequence(string &s, int i, string storage){
	
	if(i == s.size())
	{
		cout<<storage<<endl;
		return;
	}
	print_subsequence(s,i + 1, storage + s[i]);
	print_subsequence(s,i + 1, storage);
}

Node *insertIntoLinkedList(vector<int> v)
{
	Node * root = NULL;
	Node * head = NULL;
	for(auto it : v){
		if(root){
			Node * temp = new Node(it);
			root->next = temp;
			root = root->next;
		}else{
			root = new Node(it);
			head = root;
		}
	}
	return head;
}

int calculateHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0; // An empty tree has height 0
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
}





void preorder_stack(TreeNode* root){

if(root == NULL) return;

  stack<TreeNode*> st;
  st.push(root);
  while(!st.empty())
  {
    TreeNode* curr = st.top();
    st.pop();
    cout<<curr->val<<" ";

    if(curr->right) st.push(curr->right);
    if(curr->left)  st.push(curr->left);
  }

}


int getMaxPathSum(TreeNode* root,TreeNode *main_root)
{
  if(root == NULL) return 0;
  int left = getMaxPathSum(root->left,main_root);
  int right= getMaxPathSum(root->right,main_root);

  int sum =  root->val < 0 ? 0 : root->val; // adding current node value to sum ( not allowing negative value)
  if(main_root == root){
    sum += max(left,0);
    sum += max(right,0);
    return sum ;
  }
  else{
    int max_value = max(left,right);
    return sum + (max_value < 0 ? 0 : max_value);
  }

  return sum;
}

void solve(){

	// vector<int> v = {1,2,3,4,5};
	// Node* ll_root = insertIntoLinkedList(v);

	// TreeNode* tree_root = new TreeNode(10);
	// tree_root->left = new TreeNode(5);
	// tree_root->right = new TreeNode(15);
	// tree_root->left->left = new TreeNode(1);
	// tree_root->left->right = new TreeNode(8);
	// tree_root->right->left = new TreeNode(11);
	// // printLL(ll_root);

	// print_preorder(tree_root);
	// cout<<endl;

	// print_inorder(tree_root);
	// cout<<endl;

	// print_postorder(tree_root);
	// cout<<endl;

	// print_levelorder(tree_root);
	// cout<<endl;

	// string s= "1234";
	// string temp = "";
	// print_subsequence(s,0,temp);

	// string input_string = "Hi Jaimit Jaimit";
	// string pattern ="Jaimit";
	// size_t pos =input_string.find(pattern);

	// while(pos != std::string::npos){
	//   cout<<"Position :  "<<pos<<endl;
	//   pos = input_string.find(pattern,pos+1);
	// }


	// TreeNode *root = new TreeNode(10);
	// root->left = new TreeNode(8);
	// root->right = new TreeNode(11);
	// root->left->right = new TreeNode(9);
	// preOrderTraversal(root);
	// levelOrderTraversal(root);


	// ########linked list - deep copy########
	// Node * root = new Node(1);
	// root->next = new Node(2);
	// root->next->next = new Node(3);

	// root->random = NULL;
	// root->next->random = root;
	// root->next->next->random = root->next;
	
	// unordered_map<Node*,Node*> mp;
	// Node* head = root;

	//  while(head){
	//      mp[head] = new Node(head->data);
	//      head = head->next;
	//  }
	//  head = root;
	//  while(head){
	//      mp[head]->next = mp[head->next];
	//      mp[head]->random = mp[head->random];         
	//      head= head->next;
	//  }
	//  return mp[root];

	// ##########Morris inorder Traversal###########
	//   TreeNode* root = new TreeNode(1);
	//   root->left = new TreeNode(2);
	//   root->right = new TreeNode(3);
	//   root->left->left = new TreeNode(4) ;
	//   root->left->right = new TreeNode(5) ;
	//   root->left->right->right = new TreeNode(6) ;

	// TreeNode * curr = root;
	// while(curr != NULL){
	
	//   if(!curr->left){
	//     cout<<curr->data<<" ";
	//     curr = curr->right;
	//   }else{
	//     TreeNode * ps = NULL;
	//     ps = curr->left;
	
	//     while(ps->right != NULL && ps->right != curr){
	//       ps = ps->right;
	//     }

	//     if(ps->right == NULL){
	//       ps->right = curr;
	//       curr = curr ->left;
	//     }
	//     else{
	//       ps->right = NULL;
	//       cout<<curr->data<<" ";
	//       curr = curr->right;
	//     }
	//   }

	// }
  

	//#########Bottom view of Binary Tree###########
	// queue<pair<TreeNode*,int>> q;
	// map<int,int> mp;
	// q.push({root,0});
	// while(!q.empty())
	// {
	//   TreeNode* curr = q.front().first;
	//   int level = q.front().second;
	//   mp[level] = curr->data;
	//   q.pop();
	
	//   if(curr->left){
	//     q.push({curr->left,level-1});
	//   }

	//   if(curr->right){
	//   q.push({curr->right,level+1});
	//   }

	// }

	// for(auto it: mp){
	//   cout<<it.first<<" : "<<it.second<<" "<<endl;
	// }


	// preorder_stack(root);
	//cout<<getMaxPathSum(root,root);

	

	//#######linked list cycle detection##########
	vector<int> v = {1,2,3,4,5};
	Node * head = insertIntoLinkedList(v);
	// printLL(head);
	// // head->next->next->next->next = head->next->next; // create Cycle

	// Node* slow = head;
	// Node* fast = head;

	// while(fast && fast->next){
	// 	slow = slow->next;
	// 	fast = fast->next->next;
	// 	if(slow == fast ){
	// 		 cout<<endl<<"There is Cycle in the list";
	// 		 break;
	// 	}
	// }

	// if(slow != fast) {
	// 	cout<<"No Cycle"<<endl;
	// 	return;
	// }

	// fast = head;
	// while(slow != fast ){
	// 	slow = slow->next;
	// 	fast = fast->next;
	// }
	// cout<<"Cycle is formed at Node : "<<slow->data<<endl;

	// //##########Delete Specific nth-Node from Linked list########;
	// // jump = n-1; to delete nth node traverse here
	
	// int n = 1;
	// if(n == 1 ){
	// 	Node * delete_node = head;
	// 	head = head->next;
	// 	delete delete_node;
	// 	printLL(head);
	// 	return;
	// }
	// int jump = n-2;
	// Node* hd = head;
	// while(jump){
	// 	hd = hd->next;
	// 	jump--;
	// }

	// Node * delete_node = hd->next;
	// hd->next = hd->next->next;
	// delete delete_node;
	// printLL(head);

	

}

int main(){


	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);

	solve();
	return 0;

}

