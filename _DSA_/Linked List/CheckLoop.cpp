#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void create(int A[], int n)
{
	int i;
	struct Node *t, *last;

	//we will create first Node since we do not have it globally
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

int isLoop(struct Node *f)
{
	struct Node *p, *q;
	p = q = f;
	do
	{
		//this will loop will stop when p or q is NULL for Linear LinkedList
		//it will stop when p = q for Loop In linked list
		p = p->next; //slow pointer 
		q = q->next; //faster pointer
		q = q ? q->next : q;
		//other case for loop to stop is p==q  
	} while (p && q && p != q);

	if (p == q)
		return 1;
	else
		return 0;
}

int main()
{

	struct Node *t1, *t2;

	int A[] = {10, 20, 30, 40, 50};
	create(A, 5);

	t1 = first->next->next;
	t2 = first->next->next->next->next;
	t2->next = t1;

	printf("%d\n", isLoop(first));

	return 0;
	
}