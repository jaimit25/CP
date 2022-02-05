// #include <iostream>
// #include <stdlib.h>
// using namespace std;

// class TreeNode
// {
// public:
// 	TreeNode *left;
// 	int data;
// 	TreeNode *right;
// };

// class Node
// {
// public:
// 	int addr;
// 	// TreeNode *addr;
// 	Node *next;
// };

// class Queues
// {
// private:
// 	Node *front;
// 	Node *last;

// public:
// 	Queues();
// 	// void Enqueue(TreeNode *add);
// 	// TreeNode *Dequeue();
// 	void Enqueue(int add);
// 	int Dequeue();
// 	bool isFull();
// 	bool isEmpty();
// 	void Display();
// 	int length();
// };

// Queues::Queues()
// {
// 	front = NULL;
// 	last = NULL;
// }

// // void Queues::Enqueue(TreeNode *add)
// // {
// // }

// // TreeNode *Queues::Dequeue()
// // {
// // }
// void Queues::Enqueue(int add)
// {
// 	if (isFull())
// 	{
// 		cout << "Queue is Full " << endl;
// 		return;
// 	}
// 	else
// 	{
// 		if (isEmpty())
// 		{
// 			//there is no node in list
// 			Node *temp = new Node;
// 			temp->addr = add;
// 			temp->next = NULL;
// 			front = last = temp;
// 		}
// 		else
// 		{

// 			//There are Nodes in list

// 			//initialized new Node
// 			Node *temp = new Node;
// 			temp->addr = add;
// 			temp->next = NULL;

// 			//setting new Node to list
// 			//inserting/Enqueue is done at the end of linked List
// 			last->next = temp;
// 			last = temp;
// 		}
// 	}
// }

// int Queues::Dequeue()
// {
// 	int x = -1;

// 	if (isEmpty())
// 	{
// 		cout << "Queue is Empty " << endl;
// 		return -1;
// 	}
// 	else
// 	{
// 		Node *p = front;
// 		x = front->addr;
// 		front = front->next;
		
// 	}
// 	return x;
// }

// bool Queues::isEmpty()
// {
// 	if (front == NULL && last == NULL)
// 	{
// 		return true;
// 	}
// 	return false;
// }

// bool Queues::isFull()
// {
// 	Node *t = new Node;
// 	if (t)
// 	{
// 		return false;
// 	}
// 	delete t;
// 	return true;
// }

// void Queues::Display()
// {
// 	Node *p = front;
// 	while (p != NULL)
// 	{
// 		cout << p->addr<< " ";
// 		p = p->next;
// 	}
// 	cout<<endl;
// }

// int Queues::length()
// {
// 	Node *p = front;
// 	int len = 0;
// 	while (p != NULL)
// 	{
// 		len++;
// 		p = p->next;
// 	}
// 	return len;
// }




#include <iostream>
#include <stdlib.h>
using namespace std;

class TreeNode
{
public:
	TreeNode *left;
	int data;
	TreeNode *right;
};

class Node
{
public:
	TreeNode *addr;
	Node *next;
};

class Queues
{
private:
	Node *front;
	Node *last;

public:
	Queues();
	void Enqueue(TreeNode *add);
	TreeNode *Dequeue();
	bool isFull();
	bool isEmpty();
	void Display();
	int length();
};

Queues::Queues()
{
	front = NULL;
	last = NULL;
}


void Queues::Enqueue(TreeNode *add)
{

	if (isFull())
	{
		cout << "Queue is Full " << endl;
		return;
	}
	else
	{
		if (isEmpty())
		{
			//there is no node in list
			Node *temp = new Node;
			temp->addr = add;
			temp->next = NULL;
			front = last = temp;
		}
		else
		{
			//There are Nodes in list

			//initialized new Node
			Node *temp = new Node;
			temp->addr = add;
			temp->next = NULL;

			//setting new Node to list
			//inserting/Enqueue is done at the end of linked List
			last->next = temp;
			last = temp;
		}
	}
}

TreeNode* Queues::Dequeue()
{
	TreeNode *x = NULL;
	
	if (isEmpty())
	{
		cout << "Queue is Empty " << endl;
		return NULL;
	}
	else
	{
		Node *p = front;
		x = front->addr;
		front = front->next;
	}

	return x;
}

bool Queues::isEmpty()
{
	if (front == NULL && last == NULL)
	{
		return true;
	}
	return false;
}

bool Queues::isFull()
{
	Node *t = new Node;
	if (t)
	{
		return false;
	}
	delete t;
	return true;
}

void Queues::Display()
{
	Node *p = front;
	while (p != NULL)
	{
		// cout << p->addr<< " ";
		p = p->next;
	}
	cout<<endl;
}

int Queues::length()
{
	Node *p = front;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}