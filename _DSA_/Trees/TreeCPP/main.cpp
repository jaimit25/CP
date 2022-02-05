#include <iostream>
#include <stdlib.h>
#include "Queue.h"
using namespace std;

class Tree
{

private:
	Node *root;

public:
	Tree() { root = NULL; }
	void createTree();
	void preorder(Node *p);
	void postorder(Node *p);
	void inorder(Node *p);
	Node *getRoot() { return root; }
};

void Tree::createTree()
{
	Node *p;
	int x, i;
	Queue q(20);
	cout << "Enter Root Node Element Value : " << endl;
	cin >> x;
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.enqueue(root);

	while (!q.isEmpty())
	{

		p = q.dequeue();

		cout << "Enter Value of Left Child for " << p->data << " : " << endl;
		cin >> x;
		if (x != -1)
		{
			Node *t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.enqueue(t);
		}

		cout << "Enter Value of Right Child for " << p->data << " : " << endl;
		cin >> x;
		if (x != -1)
		{
			Node *t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.enqueue(t);
		}
	}
}

void Tree::preorder(Node *p)
{
	if (p)
	{
		cout << p->data << ", " << flush;
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void Tree::postorder(Node *p)
{
	if (p)
	{
		preorder(p->lchild);
		preorder(p->rchild);
		cout << p->data << endl;
	}
}
void Tree::inorder(Node *p)
{
	if (p)
	{
		preorder(p->lchild);
		cout << p->data << endl;
		preorder(p->rchild);
	}
}

int main()
{

	Tree tr;
	tr.createTree();
	tr.preorder(tr.getRoot());

	return 0;
}
