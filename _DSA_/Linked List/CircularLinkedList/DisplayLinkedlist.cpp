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
	cout<<endl;
}

void RDisplay(struct Node *p){
	static int flag = 0;
	if(p != Head || flag == 0){
		flag = 1;
		cout<<p->data<<" ";
		RDisplay(p->next);
	}
	flag = 0;
}

int main()
{
	int A[] = {2, 3, 4, 5, 6};
	create(A, 5);
	Display(Head);
	cout<<"Recursive Display"<<endl;
	RDisplay(Head);
	cout<<endl;
	return 0;
}