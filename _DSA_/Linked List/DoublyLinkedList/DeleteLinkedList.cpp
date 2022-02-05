#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
} *first = NULL;

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
	struct Node *q = p;
	cout << endl;
	cout << "Displaying Linked List : " << endl;
	while (p != NULL)
	{
		cout<< p->data <<" ";
		p = p->next;
	}
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

void Insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i = 0;
	if (index == 0)
	{
		t = new Node;
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 2; i++)
		{
			p = p->next;
		}
		t = new Node;
		t->data = x;
 		t->prev = p;
		t->next = p->next;
		if (p->next != NULL)
		{
			p->next->prev = t;
		}
		p->next = t;
	}
}

int Delete(struct Node *p, int index){
	int x = -1,i;
	if(index < 1 || index  > Length(p)){
		return -1;
	}
	else{
		if(index == 1){
			//deleting first Node from the linked list 
			p = first;
			x = p->data;
			first = first->next;
			delete p;
			if(first != NULL){
				first->prev = NULL;
			}

		}else{
			for(i = 0;i < index-1; i++){
				p = p->next;
			}

			p->prev->next = p->next;
			if(p->next != NULL){
				//if p->next is not last node
				p->next->prev = p->prev;
			}
			x = p->data;
			delete p;
		}
	}
	return x;
}
void Reverse(struct Node *p){
	struct Node *temp;
	while(p != NULL){
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p=p->prev;
		if( p!=NULL && p->next == NULL){
			first = p;
		}
	}
}
int main()
{

	int A[] = {1, 2, 5, 7, 9};
	Create(first, A, 5);
	Display(first);
	Insert(first, 2, 64);	
	Display(first);
	Delete(first,6);
	Display(first);
	Reverse(first);
	Display(first);

	return 0;
}