#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *first;

public:
	LinkedList()
	{
		first = NULL;
	}
	LinkedList(int A[], int n);
	void Display();
	void Insert(int index, int x);
	void Delete(int index);
	int Length(struct Node *p);
	Node *getFirst();
	~LinkedList();
};

LinkedList::LinkedList(int A[], int n)
{
	 int i;
	//creating first Node
	Node *first_node = NULL, *last_node = NULL;
	first_node = new Node;
	first_node->data = A[0];
	first_node->next = NULL;
	first = first_node;
	last_node = first_node;
	for (i = 1; i < n; i++)
	{
		Node *t = new Node;
		t->data = A[i];
		t->next = NULL;
		last_node->next = t;
		last_node = t;
	}
}

Node *LinkedList::getFirst()
{
	return first;
}

int LinkedList::Length(Node *p)
{
	p = first;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void LinkedList::Display()
{
	Node *p = first;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void LinkedList::Delete(int index)
{
	Node *q = NULL, *p = first;
	int i = 0;
	if (index == 1)
	{
		//we will delete first node
		q = first;
		first = first->next;
		delete q;
	}
	else
	{
		//we will delete other Node
		for (i = 0; i < (index - 1); i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
	}
}

void LinkedList::Insert(int index, int x)
{
	int i;
	struct Node *p;
	Node *t;
	t = new Node;
	t->data = x;
	if (index == 1)
	{
		if (first == NULL)
		{
			t->next = NULL;
			first = t;
		}
		else
		{
			t->next = first;
			first = t;
		}
	}
	else
	{
		p = first;
		for (i = 1; i < index - 1; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
}

LinkedList::~LinkedList()
{
	//Deleting every Memory Location
	Node *p = first;

	while (first != NULL)
	{
		first = first->next;
		delete p;
		p = first;
	}
	cout << "Linked List Deleted" << endl;
}

int main()
{
	LinkedList l;
	l.Insert(1, 12);
	l.Insert(2, 21);
	l.Insert(3, 56);
	l.Insert(4, 32);
	l.Display();
	l.Insert(1, 69);
	l.Display();
	l.Delete(2);
	l.Display();
	cout << "Length of Linked List is : " << l.Length(l.getFirst()) << endl;
	cout<<endl;
	int A[] = {1,2,3,4,5};
	LinkedList l2(A,5);
	l2.Display();
	cout << "Length of Linked List 2 is : " << l2.Length(l.getFirst()) << endl;
	cout<<endl;
	cout<<"Both The Linked List will be out of Scope now and Destructor will be Called. "<<endl;
	return 0;
}