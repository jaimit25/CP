#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
	int data;
	struct Node *next;
};

class Stack
{
private:
	Node *Top;
public:
	Stack(){
		Top = NULL;
	}
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
	void Display()
	{
		struct Node *p = Top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};

int main()
{
	Stack l;
	l.push(21);
	l.push(43);
	l.push(69);
	l.push(90);
	l.push(89);
	cout << l.peek(1) << endl;
	cout << l.peek(2) << endl;
	cout << l.peek(3) << endl;
	cout << l.peek(4) << endl;
	l.Display();
	cout << "pop : " << l.pop() << endl;
	l.Display();
	cout << "Top is : " << l.stackTop() << endl;
	cout << "Empty : " << l.isEmpty() << endl;
	cout << "Full : " << l.isFull() << endl;

	return 0;
}