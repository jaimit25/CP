#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
} *Top = NULL;


int pop()
{
	int x = -1;
	if (Top == NULL)
	{
		cout << "Stack Underflow" << endl;
		return -1;
	}
	else
	{
		struct Node *p = Top;
		x = Top->data;
		Top = Top->next;
		delete p;
	}
	return x;
}

int isFull()
{
	//we will create a node and check if that node is
	//created and if it is not created then we dont have space in heap.
	struct Node *t = new Node;
	int x = t ? 0 : 1;
	return x;
}
int isEmpty()
{
	if (Top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int peek(int pos)
{
	int i = 0;
	int x = -1;
	struct Node *p = Top;
	for (i = 0; p != NULL && i < pos - 1; i++)
	{
		p = p->next;
	}
	if (p != NULL)
		return p->data;
	else
		return -1;
}

int stackTop()
{
	return Top->data;
}

void push(int x)
{
	struct Node *t = new Node;
	if (t == NULL)
	{
		cout << "Stack Overflow" << endl;
	}
	else
	{
		t->data = x;
		t->next = Top;
		Top = t;
	}
}
void Display(){
	struct Node *p = Top;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	push(21);
	push(43);
	push(69);
	push(90);
	push(89);
	cout<<peek(1)<<endl;
	cout<<peek(2)<<endl;
	cout<<peek(3)<<endl;
	cout<<peek(4)<<endl;
	Display();

	cout<<"pop : "<<pop()<<endl;
	Display();


	cout<<"Top is : "<<stackTop()<<endl;

	cout<<"Empty : "<<isEmpty()<<endl;
	cout<<"Full : "<<isFull()<<endl;

	return 0;

}