#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int Data;
	struct Node *next;
} * first; //we created a Global pointer name first

void Display(struct Node *p)
{
	if (p!= NULL)
	{
		cout << p->Data << " ";
		Display(p->next);
	}
}

void RDisplay(struct Node *p)
{
	if (p!= NULL)
	{
		Display(p->next);
		cout << p->Data << " ";
	}
}

// void Display(struct Node *p)
// {
// 	while (p != NULL)
// 	{
// 		printf("%d ", p->Data);
// 		p = p->next;
// 	}
// }
// void RDisplay(struct Node *p)
// {
// 	if (p != NULL)
// 	{
// 		RDisplay(p->next);
// 		printf("%d ", p->Data);
// 	}
// }

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
	//         0  1  2  3    4   5  6  7
	int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
	Create(A, 8);
	// Display(first);
	// cout << "*********" << endl;
	// ReverseDisplay(first);

	Display(first);
	cout << "*********" << endl;
	RDisplay(first);

	return 0;
}