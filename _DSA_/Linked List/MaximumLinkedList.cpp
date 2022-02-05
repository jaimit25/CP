#include <iostream>
#include <stdlib.h>
#include <math.h>

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
		cout << p->Data << "  ";
		p = p->next;
	}
	cout << endl;
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
int RLength(struct Node *p)
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return RLength(p->next) + 1;
	}
}

int Sum(struct Node *p)
{
	int add = 0;
	while (p != NULL)
	{
		add = add + p->Data;
		p = p->next;
	}
	return add;
}
int RSum(struct Node *p)
{

	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return RSum(p->next) + p->Data;
	}
}
int Max(struct Node *p)
{
	int max = INT32_MIN;
	while (p != NULL)
	{
		if (p->Data > max)
		{
			max = p->Data;
		}
		p = p->next;
	}
	return max;
}
int RMax(struct Node *p)
{
	int x = 0;

	if (p == NULL)
	{
		return INT32_MIN;
	}
	else
	{
		x = RMax(p->next);
		if (p->Data > x)
			return p->Data;
		else
			return x;
	}
}

int main()
{
	//         0 1 2  3  4 5  6 7
	int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
	Create(A, 8);
	Display(first);
	cout << Length(first) << endl;
	cout << RLength(first) << endl;
	cout << "Sum of All Elements is : " << Sum(first) << endl;
	cout << "Sum of All Elements is : " << RSum(first) << endl;
	cout << "Maximum is : " << Max(first) << endl;
	cout << "Maximum is : " << RMax(first) << endl;

	return 0;
}