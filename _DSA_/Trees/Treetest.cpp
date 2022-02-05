#include <iostream>
#include <stdlib.h>
#include "Queues.h"

using namespace std;

TreeNode *root;
void Preorder( TreeNode *p)
{
	if (p)
	{
		cout<<p->data<<" ";
		Preorder(p->left);
		Preorder(p->right);
	}
}

void createTree()
{
	Queues q;
	int val;
	TreeNode *p;

	cout << "Enter Val1 : " << endl;
	root = new TreeNode;
	cin >> root->data;
	root->left = root->right = NULL;
	q.Enqueue(root);
	cout<<"Length of Linked list is : "<<q.length()<<endl;


	while (!q.isEmpty())
	{
		p = q.Dequeue();

		cout << "Enter Value of Left Child " << p->data << " : ";
		cin >> val;
		if (val != -1)
		{
			//initializing new Node
			TreeNode *t = new TreeNode;
			t->left = t->right = NULL;
			t->data = val;

			//Attaching New Node to the currently pointed Node by p on the left side of the tree
			p->left = t;
			q.Enqueue(t);
			cout<<"Length of Linked list is : "<<q.length()<<endl;
		}
		cout << "Enter Value of Right Child " << p->data << " : ";
		cin >> val;
		if (val != -1)
		{
			//initializing new Node
			TreeNode *t = new TreeNode;
			t->left = t->right = NULL;
			t->data = val;

			//Attaching New Node to the currently pointed Node by p on the left side of the tree
			p->right = t;
			q.Enqueue(t);
			cout<<"Length of Linked list is : "<<q.length()<<endl;
		}
	}
}

int main()
{

	// Queues s;
	// s.Enqueue(1);
	// s.Enqueue(2);
	// s.Enqueue(3);
	// s.Enqueue(4);
	// s.Display();
	createTree();
	Preorder(root);
	return 0;
}