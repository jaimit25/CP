#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *lchild;
	int data;
	Node *rchild;
} *root = NULL;

void Inorder(Node *p)
{
	if (p != NULL)
	{
		Inorder(p->lchild);
		cout << p->data << " ";
		Inorder(p->rchild);
	}
}

void Insert(int key)
{
	struct Node *t = root;
	struct Node *r, *p;

	if (t == NULL)
	{
		// for first Node
		root = new Node;
		root->data = key;
		root->lchild = root->rchild = NULL;
		return;
	}
	else
	{
		//if we already have first Node
		while (t != NULL)
		{
			r = t;
			if (t->data < key)
				t = t->rchild;
			else if (t->data > key)
				t = t->lchild;
			else if (key == t->data)
				return;
		}

		p = new Node;
		p->data = key;
		p->lchild = p->rchild = NULL;

		if (r->data > key)
			r->lchild = p;
		else if (r->data < key)
			r->rchild = p;
	}
}

Node *RInsert(Node *p, int key)
{

	Node *t = NULL;

	if (p == NULL)
	{
		t = new Node;
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if (key < p->data)
	{
		p->lchild = RInsert(p->lchild, key);
	}
	else if (key > p->data)
	{
		p->rchild = RInsert(p->rchild, key);
	}

	return p;
}

Node *Rsearch(struct Node *t, int key)
{
	if (t == NULL)
		return NULL;
	if (key == t->data)
		return t;
	else if (key < t->data)
		return Rsearch(t->lchild, key);
	else
		return Rsearch(t->rchild, key);
}

struct Node *Search(int key)
{
	Node *t = root;

	while (t)
	{

		if (key == t->data)
		{
			return t;
		}
		else if (t->data > key)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}

	return NULL;
}

int Height(struct Node *p)
{
	int x, y;
	if (p == NULL)
		return 0;

	x = Height(p->lchild);
	y = Height(p->rchild);

	if (x > y)
	{
		return x + 1;
	}
	else
	{
		return y + 1;
	}
}

Node *InPre(Node *p)
{

	while (p && p->rchild != NULL)
	{
		p = p->rchild;
	}
	return p;
}

Node *InSuc(Node *p)
{
	while (p && p->lchild != NULL)
	{
		p = p->lchild;
	}
	return p;
}

struct Node *Delete(struct Node *p, int key)
{

	struct Node *q;

	//finally when to delete a Node
	//if we have reach the leaf node
	if (p == NULL)
	{
		//if the key is not present then we have nothing to delete so we dont do anything
		return NULL;
	}

	if (p->lchild ==NULL && p->rchild == NULL)
	{
		//before deleting we have to check if p is a root Node
		if (p == root)
		{
			root = NULL;
		}
		delete p;
		return NULL;
	}

	//initial step navigating to the key
	if (key > p->data)
	{
		p->rchild = Delete(p->rchild, key);
	}
	else if (key < p->data)
	{
		p->lchild = Delete(p->lchild, key);
	}
	else
	{
		//key is found we can replace that element with inorder predecessor or inorder successor
		// if height of left subtree is more then we will delete element or choose inorder predecessor
		//vice versa for right subtree
		//we repeat this function until we reach the left value to be made as the deleted value

		if (Height(p->lchild) > Height(p->rchild))
		{
			//we will store inorder predecessor in q
			q = InPre(p->lchild);

			//after finding element
			p->data = q->data;

			//now we have to delete the inorder predessor Node so we again call the Same
			//function so that we can delete also if inorder predecessor also has child
			//so thats why we call this function recursively again

			p->lchild = Delete(p->lchild, q->data);
		}
		else
		{
			q = InSuc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}

	}
	return p;

}

int main()
{
	// Insert(10);
	// Insert(5);
	// Insert(20);
	// Insert(8);
	// Insert(30);

	// Insert Function
	root = RInsert(root, 10);
	RInsert(root, 5);
	RInsert(root, 20);
	RInsert(root, 8);
	RInsert(root, 30);

	Inorder(root);
	cout << endl;


	//Delete Function
	cout<<"Deleting Element : "<<Delete(root,10)->data<<endl;
	cout<<"Deleting Element : "<<Delete(root,5)->data<<endl;

	Inorder(root);
	cout << endl;

	// cout << Search(10)->data << endl;
	// cout << Rsearch(root, 20)->data << endl;

	return 0;
}