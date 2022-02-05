#include <iostream>
// #include "Queues.h"
#include "TreeCreate/Queues.h"
using namespace std;

Node *root ;
void Preorder( Node *p)
{
	if (p)
	{
		cout<<p->data<<" ";
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void createTree()
{

	Queue q;
	create(&q,100);
	 root = new Node;
	cout << "Enter Root Node value  : " << endl;
	cin >> root->data;
	root->lchild = root->rchild = NULL;
	enqueue(&q,root);
	
	int x;
	while (!isEmpty(q))
	{
		Node *a = dequeue(&q);

		cout << "Enter Left Child of  "<<a->data<<" : "<<endl;
		cin >> x;
		if (x != -1)
		{
			Node *t = new Node;
			t->lchild = t->rchild = NULL;
			t->data = x;
			a->lchild = t;
			enqueue(&q,t);

		}
		cout << "Enter Right Child "<<a->data<<" : "<< endl;
		cin >> x;
		if (x != -1)
		{
			Node *t = new Node;
			t->lchild = t->rchild = NULL;
			t->data = x;
			a->rchild = t;
			enqueue(&q,t);
		}
	}

	Preorder(root);
}


void levelorder()
{ 
	struct Queue q;
	create(&q,100);

	Node *p = root;
	enqueue(&q,p);

	while (!isEmpty(q)){
		p = dequeue(&q);
		cout<< p->data<<" ";
		if (p->lchild){
			enqueue(&q,p->lchild);

		}
		if(p->rchild){
			enqueue(&q,p->rchild);
		}
	}

}

int count(Node *p){
	//counting number of nodes
	if(p){
		return count(p->lchild)+count(p->rchild)+1;
	}
	return 0;
}	

int height(Node *root){

	int x = 0 , y = 0;
	if(root == NULL)
		return 0;

	x = height(root->lchild);
	y = height(root->rchild);
	if(x>y)
		return x+1;
	else  //  this case will work for x = y and y < x
		return y+1;	
}


int main()
{
	createTree();
	cout<<endl;
	levelorder();
	cout<<endl;

	cout<<"Height of tree is : "<<height(root)<<endl;
	cout<<"Number of nodes in tree is : "<<count(root)<<endl;

	return 0;
}
