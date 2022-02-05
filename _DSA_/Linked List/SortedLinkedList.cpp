#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int Data;
	struct Node *next;
} * first; //we created a Global pointer name first

void Display(struct Node *first)
{
	struct Node *p = first;
	while (p != NULL)
	{
		cout << p->Data << " ";
		p = p->next;
	}
	cout << endl;
}

struct Node *Search(struct Node *p, int key)
{
	while (p != NULL)
	{
		if (p->Data == key)
		{
			return (p);
		}
		p = p->next;
	}

	return NULL;
}
struct Node *RSearch(struct Node *p, int key)
{
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		if (p->Data == key)
		{
			return p;
		}
		else
		{
			return RSearch(p = p->next, key);
		}
	}
}

// struct Node *
void SearchImproved(struct Node *p, int key)
{
	struct Node *q = NULL;
	while (p != NULL)
	{
		if (key == p->Data)
		{
			//we will assign p->next to q->next
			q->next = p->next;
			p->next = first;
			first = p;
		}
		q = p;
		p = p->next;
		//now if we search and element it will be found at
		//the first position of linked list
	}
}

void Create(int A[], int n)
{
	//we will transverse through Array and create a linked list of Data elements
	int i;
	//we create two node for tracking first and last element
	struct Node *t, *last;

	//we have created the first Node of The Linked List
	first = (struct Node *)malloc(sizeof(struct Node));
	first->Data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->Data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
int Length(struct Node *p)
{
	int length = 0;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}

void Insert(struct Node *p, int index, int x)
{
	//ceating new pointer for inserting
	struct Node *t;
	int i = 0;
	//checking if inserting is valid or Not
	if (index < 0 || index > Length(p))
	{
		return;
	}
	else
	{

		//initialing and inserting value into new Node
		t = new Node;
		t->Data = x;
		if (index == 0)
		{
			//we insert as first Node
			t->next = first;
			first = t;
		}

		else
		{
			for (i = 0; i < (index - 1); i++)
				p = p->next;
			t->next = p->next;
			p->next = t;
		}
	}
}
void InsertSortedList(struct Node *p, int val)
{
	struct Node *q = NULL;
	struct Node *t;

	while (p != NULL && p->Data < val)
	{
		q = p;
		p = p->next;
	}
	//initialized new Node
	t = new Node;
	t->Data = val;
	
	if(q == NULL){
		cout<<"Cannot Insert At the beginning of Node"<<endl;
	}
	else{
	t->next = q->next;
	q->next = t;
	}
}
void InsertSortedListLecture(struct Node *p, int val)
{
	struct Node *q = NULL;
	struct Node *t;

	//initialized new Node
	t = new Node;
	t->Data = val;
	t->next = NULL;
	if(first == NULL){
		first = t;
	}
	else{
		while(p != NULL && p->Data < val){
			q = p;
			p = p->next;
		}
		if(p == first){
			//if there is only one element in linked list 
			t->next = first;
			first = t;
		}else{
			//if there are multiple elements in list
			t ->next  = q -> next;
			q -> next  = t; 
		}
	}
}

int main()
{
	//         0  1  2
	// int A[] = {3, 5, 7};
	// Create(A, 3);
	// Display(first);

	//Inserting element into new Node
	Insert(first, 0, 12);
	Insert(first, 1, 14);
	Insert(first, 2, 16);
	Insert(first, 3, 19);
	InsertSortedList(first, 18);
	InsertSortedList(first, 13);
	InsertSortedListLecture(first, 4);
	Display(first);
	return 0;
}