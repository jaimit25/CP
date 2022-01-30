#include <iostream>
using namespace std;

class Node
{

public:
	int data;
	Node *next;
};

class Queue
{
	//Enqueue is done at end of linked list
private:
	Node *front, *rear;

public:
	Queue();
	void enqueue(int);
	int dequeue();
	void display();
};

Queue::Queue()
{
	front = rear = NULL;
}

void Queue::enqueue(int val)
{
	Node *t = new Node;
	t->data = val;
	t->next = NULL;
	if (t == NULL)
	{
		return;
	}
	if (front == NULL && rear == NULL)
	{
		//No Node
		front = rear = t;
	}
	else
	{
		//there are nodes in linked list
		rear->next = t;
		rear = t;
	}
}

int Queue::dequeue()
{
	Node *p;
	int x = -1;
	if (!front && !rear)
	{
		return -1;
	}
	else
	{
		//There are/is node's/node in linked list
		if (front == rear)
		{
			//there is only one node in linked list
			p = front;
			front = rear = NULL;
			x = p->data;
			delete p;
		}
		else
		{
			//there are multiple nodes in linked list
			p = front;
			front = front->next;
			x = p->data;
			delete p;
		}
	}
	return x;
}

void Queue::display()
{
	Node *p = front;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{

	Queue q;
	q.enqueue(12);
	q.enqueue(31);
	q.enqueue(89);
	q.enqueue(90);
	q.display();
	cout<<"Dequeue Element is : "<<q.dequeue()<<endl;
	q.display();
	q.dequeue();
	q.display();


	


	return 0;
}