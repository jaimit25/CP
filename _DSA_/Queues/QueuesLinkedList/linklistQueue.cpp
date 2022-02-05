//queue using linked list
//operations Enqueue Dequeue
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
} *rear = NULL, *front = NULL;

void Enqueue(int x)
{
	struct Node *t = new Node;
	t->data = x;
	if (t == NULL)
	{
		cout << "Queue is Full" << endl;
	}
	else if (front == NULL)
	{
		front = rear = t;
		t->next = NULL;
	}
	else
	{
		rear->next = t;
		rear = t;
	}
}

int Dequeue()
{
	int x = -1;
	struct Node *q = front;
	if (rear == NULL)
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		front = front->next;
		x = q->data;
		delete q;
	}
	return x;
}

void Display()
{
	struct Node *p = front;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{

	Enqueue(12);
	Enqueue(19);
	Enqueue(15);
	Enqueue(17);
	Display();
	Dequeue();
	Display();

	return 0;
}
