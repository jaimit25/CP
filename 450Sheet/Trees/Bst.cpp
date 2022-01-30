#include <iostream>
#include "Queue.h"
using namespace std;

//KEYBOARD SHORCUT
// Delete: Delete the previous character.
// Option+Delete: Delete the previous word.
// Function+Delete: Delete the next character (like the Delete key on Windows.)
// Function+Option+Delete: Delete the next word.
// Command+Delete: Delete the line to the left of the cursor.
// Shift+Command+Delete: Delete the line to the right of the cursor.

class TNode
{
public:
	TNode *l, *r;
	int data;
};

class Bst
{
private:
	TNode *root;
	TNode *insertNode(TNode *, int);
	void preorderTraversal(TNode *);
	TNode *getPred(TNode *);
	TNode *getSucc(TNode *);
	TNode *deleteNode(TNode *, int);

public:
	Bst();
	void insert(int);
	TNode *search(TNode *, int);
	int getPre();
	int getSuc();
	int dlt(int);
	int getHeight(TNode *);
	int height();
	void preorder();
};

int Bst::dlt(int val)
{
	return (deleteNode(root, val)->data);
}

TNode *Bst::deleteNode(TNode *p, int key)
{

	TNode *in;
	//if value is NULL
	if (p == NULL)
	{
		return NULL;
	}

	if (p->l == NULL && p->r == NULL)
	{
		//before deleting we have to check if p is a root Node
		if (p == root)
		{
			root = NULL;
		}
		delete p;
		return NULL;
	}

	if (key < p->data)
	{
		//lchild
		p->l = deleteNode(p->l, key);
	}
	else if (key > p->data)
	{
		//rchild
		p->r = deleteNode(p->r, key);
	}
	else
	{
		//we got the key
		//we will find inorder predecessor and inorder successor
		if (getHeight(p->l) > getHeight(p->r))
		{
			//if height of left child is greater
			in = getPred(p->l);
			p->data = in->data;
			p->l = deleteNode(p->l, in->data);
		}
		else
		{
			//if heigth of right child is greater
			in = getSucc(p->r);
			p->data = in->data;
			p->l = deleteNode(p->r, in->data);
		}
	}
	
	return p;
}

int Bst::height()
{
	return getHeight(root);
}

int Bst::getHeight(TNode *h)
{
	int lft, rgt;

	if ((!h))
	{
		return 0;
	}

	lft = getHeight(h->l);
	rgt = getHeight(h->r);

	if (lft > rgt)
	{
		//left is greater
		return (lft + 1);
	}
	else
	{
		//this will handle two cases
		//left == rgt and rgt is greater
		return (rgt + 1);
	}
}

int Bst::getPre()
{
	return (getPred(root->l)->data);
}
int Bst::getSuc()
{
	return (getSucc(root->r)->data);
}

TNode *Bst::getPred(TNode *p)
{
	// if (p->r)
	// {
	// 	cout << "this value is null" << endl;
	// }
	if (p && p->r)
	{
		p = getPred(p->r);
	}

	return p;
}

TNode *Bst::getSucc(TNode *s)
{
	if (s && s->l)
	{
		s = getPred(s->l);
	}

	return s;
}

void Bst::preorder()
{
	preorderTraversal(root);
	cout << endl;
}

void Bst::preorderTraversal(TNode *p)
{
	if (p)
	{
		cout << p->data << " ";
		preorderTraversal(p->l);
		preorderTraversal(p->r);
	}
}

Bst::Bst()
{
	root = NULL;
}

void Bst::insert(int key)
{
	root = insertNode(root, key);
}

TNode *Bst::insertNode(TNode *i, int val)
{
	TNode *t = new TNode;
	if (i == NULL)
	{
		//there are no nodes in Tree
		t->data = val;
		t->l = t->r = NULL;
		return t;
	}

	//there are nodes in Tree
	if (val < i->data)
	{
		//left
		i->l = insertNode(i->l, val);
	}
	else if (val > i->data)
	{
		//right
		i->r = insertNode(i->r, val);
	}
	else
	{
		cout << "Node Already Present " << endl;
	}
	return i;
}

TNode *Bst::search(TNode *s, int key)
{
	static TNode *p;

	if (s->data == key)
		return s;
	else if (s == NULL)
		return NULL;

	if (key > s->data)
		p = search(s->r, key);
	else if (key < s->data)
		p = search(s->l, key);

	return p;
}

int main()
{
	Bst bst1;
	bst1.insert(13);
	bst1.insert(10);
	bst1.insert(51);
	bst1.insert(9);
	bst1.insert(11);
	bst1.insert(49);
	bst1.insert(56);
	bst1.insert(12);
	bst1.preorder();
	// cout << "Predecessor of the Binary Search Tree is : " << bst1.getPre() << endl;
	// cout << "Successor of the Binary Search Tree is : " << bst1.getSuc() << endl;
	cout << " Node Deleted " << bst1.dlt(12) << endl;
	bst1.preorder();

	// bst1.insert(10);
	// bst1.insert(9);
	// bst1.insert(8);
	// bst1.insert(12);
	// bst1.insert(13);

	// bst1.preorder();
	// cout << "height is binary search tree : " << bst1.height() << endl;

	return 0;
}