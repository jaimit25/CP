#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
} * first;

void Create(struct Node *p, int A[], int n)
{
	int i = 0;
	struct Node *t = NULL, *last = NULL;
	first = new Node;
	first->next = NULL;
	first->prev = NULL;
	first->data = A[0];
	last = first;

	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}
}

void Display(struct Node *p)
{
	struct Node *q=p;
	cout << endl;
	cout << "Displaying Linked List : " << endl;
	cout<<"NULL";
	while (p != NULL)
	{
		cout<<" <-|-|" << p->data << "|-|-> ";
		p = p->next;
	}
	cout<<"NULL";
	cout << endl;
}

int Length(struct Node *p)
{
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}
int main()
{

	int A[] = {1, 2, 5, 7, 9};
	Create(first, A, 5);

	Display(first);
	cout << endl
	     << "Length of Linked list is : " << Length(first)<<endl<< endl;
	return 0;
}