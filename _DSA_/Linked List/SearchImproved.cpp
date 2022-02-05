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
	cout<<endl;
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
		if ( key == p ->Data)
		{
			//we will assign p->next to q->next
			q -> next  =  p -> next;
			p -> next  =  first;
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

int main()
{
	//         0 1 2  3  4 5  6 7
	int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
	Create(A, 8);
	Display(first);
	cout<<Search(first,7)<<endl;
	cout<<RSearch(first,7)<<endl;
	Display(first);
	// cout<<SearchImproved(first,7)<<endl;
	Display(first);
	return 0;
}