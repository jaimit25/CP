#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int Data;
	struct Node *next;
} *first = NULL, *second = NULL, *third = NULL; //we created a Global pointer name first

//12 functions on linked list
int Length(struct Node *p);
void Display(struct Node *first);
struct Node *Search(struct Node *p, int key);
struct Node *RSearch(struct Node *p, int key);
void SearchImproved(struct Node *p, int key);
void Create(int A[], int n);
void Insert(struct Node *p, int index, int x);
void InsertSortedList(struct Node *p, int val);
void InsertSortedListLecture(struct Node *p, int val);
int Delete(struct Node *p, int index);
int Length(struct Node *p);
void ReverseLinkListElement(struct Node *p);

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
void CreateB(int B[], int n)
{
	//we will transverse through Array and create a linked list of Data elements
	int i;
	//we create two node for tracking first and last element
	struct Node *t, *last;

	//we have created the first Node of The Linked List
	second = (struct Node *)malloc(sizeof(struct Node));
	second->Data = B[0];
	second->next = NULL;
	last = second;

	for (i = 1; i < n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->Data = B[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
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

	if (q == NULL)
	{
		cout << "Cannot Insert At the beginning of Node" << endl;
	}
	else
	{
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
	if (first == NULL)
	{
		first = t;
	}
	else
	{
		while (p != NULL && p->Data < val)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			//if there is only one element in linked list
			t->next = first;
			first = t;
		}
		else
		{
			//if there are multiple elements in list
			t->next = q->next;
			q->next = t;
		}
	}
}
int Delete(struct Node *p, int index)
{
	struct Node *q;
	int x = -1, i;
	if (index == 1)
	{
		x = first->Data;
		p = first;
		first = first->next;
		delete p;
	}
	else
	{
		p = first;
		q = NULL;
		for (i = 0; i < index - 1 && p; i++)
		{
			q = p;
			p = p->next;
		}
		if (p != NULL)
		{
			q->next = p->next;
			x = p->Data;
			free(p);
		}
	}
	return x;
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

void ReverseLinkListElement(struct Node *p)
{
	//we need length of linked list to create an Array to store elements
	//so we will use length function to get the length of an Arrays
	int *A; //A is the Array we Are Going to Use
	int i = 0;
	struct Node *q = p;
	A = (int *)malloc(Length(p) * sizeof(int));
	while (q != NULL)
	{
		A[i] = q->Data;
		q = q->next;
		i++;
	}
	q = p;
	i--;
	while (q != NULL)
	{
		q->Data = A[i];
		q = q->next;
		i--;
	}
}
void ReverseSlidingPointer(struct Node *p)
{
	struct Node *q, *r;
	q = r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}
void Concatenate(struct Node *p, struct Node *q)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
	q = NULL;
}
void MergeLinkedList()
{
	struct Node *last;

	//initial step
	if (first->Data < second->Data)
	{
		third = last = first;
		first = first->next;
		last->next = NULL;
	}
	else
	{
		third = last = second;
		second = second->next;
		last->next = NULL;
	}

	//intermediate step
	while (first != NULL && second != NULL)
	{

		if (first->Data < second->Data)
		{

			last->next = first;
			last = first;
			first = first->next;
			last->next = NULL;
		}
		else
		{

			last->next = second;
			last = second;
			second = second->next;
			last->next = NULL;
		}
	}
	if (first != NULL)
	{
		last->next = first;
	}
	else
	{

		last->next = second;
	}
}

int main()
{
	//         0  1  2
	int A[] = {3, 5, 7};
	int B[] = {6, 19, 14, 26};
	Create(A, 3);
	CreateB(B, 4);
	Display(first);
	Display(second);

	//concatenate two linked list
	// Concatenate(first,second);
	// Display(first);

	cout << "Merging Two Linked List : " << endl;
	MergeLinkedList();
	Display(third);
	return 0;
}