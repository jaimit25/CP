#include <iostream>
using namespace std;

template <class N>
class Node
{

public:
	N data;
	Node *next;
};


template <class T>
class Queue
{
	//Enqueue is done at end of linked list
private:
	Node<T> *front, *rear;

public:
	Queue();
	void enqueue(T);
	T dequeue();
	void display();
	bool empty();
};

template <class T>
Queue<T>::Queue()
{
	front = rear = NULL;
}

template <class T>
bool Queue<T>::empty()
{
	if(front == NULL && rear == NULL)
		return true;

	return false;	
}

template<class T>	
void Queue<T>::enqueue(T val)
{
	Node<T> *t = new Node<T>;
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

template <class T>
T Queue<T>::dequeue()
{
	Node<T> *p;
	T x ;
	if (!front && !rear)
	{
		return x;
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

template <class T>
void Queue<T>::display()
{
	Node<T> *p = front;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

// int main()
// {

// 	Queue<float> q;
// 	q.enqueue(12);
// 	q.enqueue(31);
// 	q.enqueue(89);
// 	q.enqueue(90);
// 	q.display();
// 	cout<<"Dequeue Element is : "<<q.dequeue()<<endl;
// 	q.display();
// 	q.dequeue();
// 	q.display();

// 	return 0;
// }