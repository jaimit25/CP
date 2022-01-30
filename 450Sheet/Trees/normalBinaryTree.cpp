#include <iostream>
// #include <queue>
#include "Queue.h"

//Extra Notes
//  cout << *q.front() << "->"; // printing values
// cout << q.front() << ' '; //printing address

using namespace std;

class TNode
{
public:
	TNode *l, *r;
	int data;
};

class Tree
{
private:
	TNode *root;

public:
	Tree();
	void createTree();
	void Preorder_traversal();
	void preorder(TNode *p);
};

Tree::Tree()
{
	root = NULL;
}

void Tree::Preorder_traversal()
{
	TNode *first = root;
	preorder(first);
}

void Tree::preorder(TNode *p)
{
	if (p)
	{
		cout << p->data << " ";
		preorder(p->l);
		preorder(p->r);
	}
}

void Tree::createTree()
{

	Queue<TNode *> q;

	root = new TNode;
	cout << "Enter value to be saved in root Node : " << endl;
	cin >> root->data;
	root->l = NULL;
	root->r = NULL;

	//pushing address of root node into q
	q.enqueue(root);

	while (!q.empty())
	{
		int in;
		TNode *n = q.dequeue();

		//left child
		cout << "Enter left child of Node " << n->data << " : ";
		TNode *lft = new TNode;
		cin >> in;

		if (in != -1)
		{
			lft->data = in;
			lft->l = lft->r = NULL;
			n->l = lft;
			q.enqueue(lft);
		}
		else
		{
			n->l = NULL;
		}

		// right child
		cout << "Enter right child of Node " << n->data << " : ";
		TNode *rgt = new TNode;
		cin >> in;
		if (in != -1)
		{
			rgt->data = in;
			rgt->r = rgt->r = NULL;
			n->r = rgt;
			q.enqueue(rgt);
		}
		else
		{
			n->r = NULL;
		}
	}
}

int main()
{
	Tree t1;
	t1.createTree();
	t1.Preorder_traversal();

	return 0;
}