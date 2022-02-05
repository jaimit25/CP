#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
} * Head;

void create(int A[], int n)
{
	int i;
	struct Node *t;
	struct Node *last;
	Head = (struct Node *)malloc(sizeof(struct Node));
	Head->data = A[0];
	Head->next = Head;
	last = Head;
	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = last->next;
		// t->next = last->Head;
		last->next = t;
		last = t;
	}
}
void Display(struct Node *p)
{
	do
	{
		cout << p->data << " ";
		p = p->next;
	} while (p != Head);
	cout << endl;
}

void RDisplay(struct Node *p)
{
	static int flag = 0;
	if (p != Head || flag == 0)
	{
		flag = 1;
		cout << p->data << " ";
		RDisplay(p->next);
	}
	flag = 0;
}
int Length(struct Node *p){
	int len = 0;
	do{
		len++;
		p = p->next;

	}while(p != Head);
	return len;
}

void Insert(int pos, int x)
{
	struct Node *p, *t;
	int i;

	if (pos == 0)
	{
		t = new Node;
		t->data = x;
		if (Head == NULL)
		{
			Head = t;
			Head->next = Head;
		}
		else
		{
			p = Head;
			while (p != Head)
			{
				p = p->next;
			}
			p->next = t;
			t->next = Head;
			Head = t;
		}
	}
	else
	{
		p = Head;
		for (i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}
		t = new Node;
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}

int main()
{
	// int A[] = {2, 3, 4, 5, 6};
	// create(A, 5);
	// Display(Head);
	// cout << "Recursive Display" << endl;
	// RDisplay(Head);
	// cout << endl;

	Insert(0,12);
	Insert(1,43);
	Insert(2,21);
	Insert(3,64);
	Display(Head);
	cout<<Length(Head)<<endl;

	return 0;
}