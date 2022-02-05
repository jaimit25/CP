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



int main()
{
	createTree();
	cout<<endl;
	levelorder();
	return 0;
}
