#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;

//Implementation of Stack, Queue, Array and Linked List Data structure with some Operations
// Array(int size);
// void Insert(T Element, int index);
// void InsertStart(T Element);
// void InsertEnd(T Element);
// T Delete(int index);
// T Sum();
// T Search(T key);
// void Reverse();
// void Display();
// int Length();
// ~Array();
// LinkedList();
// void InsertHead(T Element);
// void InsertLast(T Element);
// void InsertBtw(T Element, int index);
// T Search(T Element);
// void Display();
// T DeleteHead();
// T DeleteLast();
// T DeleteBtw(int index);
// int sum();
// int Length();
// ~LinkedList()
// Stack();
// void push(T Element);
// T pop();
// T peek(int pos);
// int isFull();
// int isEmpty();
// void Display();
// int stackTop();
// int Sum();
// Queue(int size);
// bool isFull();
// bool isEmpty();
// void enqueue(T x);
// T dequeue();
// void display();
// ~Queue()

    //Operations on Array:
    //Insert
    //InsertStart
    //InsertEnd
    //Delete
    //Sum
    //Search
    //Reverse
    //Display
    template <class T>
    class Array
{
public:
	int size;
	int length;
	T *A;
	Array(int size);
	void Insert(T Element, int index);
	void InsertStart(T Element);
	void InsertEnd(T Element);
	T Delete(int index);
	T Sum();
	T Search(T key);
	void Reverse();
	void Display();
	int Length();
	~Array()
	{
		delete[] A;
		cout << "Array Class Destroyed" << endl;
	}
};

template <class T>
Array<T>::Array(int size)
{
	this->size = size;
	A = new int[size];
	length = 0;
}

template <class T>
void Array<T>::Insert(T Element, int index)
{
	int i = 0; // we create a index pointer to loop through the Array to shift element

	if (length == size)
	{
		cout << "Array is Full";
	}
	else
	{
		// cout << length << endl;
		for (i = length; i > index; i--)
		{
			A[i] = A[i - 1];
		}
		A[index] = Element;
		length++;
	}
}

template <class T>
void Array<T>::InsertStart(T Element)
{
	//when Entering we have to shift all the elements to the next Location and we have to start from the end of the Array
	int i = 0; // we create a index pointer to loop through the Array to shift element

	if (length == size)
	{
		cout << "Array is Full";
	}
	else
	{
		// cout << length << endl;
		for (i = length; i > 0; i--)
		{
			A[i] = A[i - 1];
		}
		A[0] = Element;
		length++;
	}
}

template <class T>
void Array<T>::InsertEnd(T Element)
{
	//for inserting at end Directly Insert at the end of the Array using length
	if (length == size)
	{
		cout << "Array is Full";
	}
	else
	{
		A[length] = Element;
		length++;
	}
}

template <class T>
T Array<T>::Delete(int index)
{
	int i = 0;
	T x = -1;

	//we will shift all the elements to the left side of Array
	if (index >= length || index == -1)
	{
		cout << "Invalid Index" << endl;
		return -1;
	}
	else
	{
		x = A[index];
	}
	for (i = index; i < length - 1; i++)
	{
		A[i] = A[i + 1];
	}
	length--;
	return x;
}

template <class T>
int Array<T>::Length()
{
	return length;
}

template <class T>
T Array<T>::Sum()
{
	int sum = 0, i = 0;
	for (i = 0; i < length; i++)
	{
		sum = sum + A[i];
	}
	return sum;
}

template <class T>
T Array<T>::Search(T key)
{

	//Implemented Binary Search we check mid element if is equal to the key we return the index
	//if mid element in array is smaller then we change value of high to mid element -1
	//if mid element in array is greater then we change value of low to mid element +1
	int l = 0, h = length - 1;

	int mid = 0;
	while (l <= h)
	{
		mid = (l + h) / 2;
		cout << "l : " << l << endl;
		cout << "h : " << h << endl;
		cout << "m : " << mid << endl;
		cout << endl;
		if (key == A[mid])
		{
			return mid;
		}
		else if (key < A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}

template <class T>
void Array<T>::Reverse()
{
	int i = 0, j = 0;
	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		cout << A[i] << " " << A[j] << endl;

		T temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}

template <class T>
void Array<T>::Display()
{
	int i = 0;
	cout << endl;
	for (i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

//It consist of Singly Linked List
class Node
{
public:
	int data;
	struct Node *next;
};

//InsertHead
//InsertLast
//InsertBtw
//Search
//Display
//DeleteHead
//DeleteLast
//DeleteBtw
//sum
template <class T>
class LinkedList
{

public:
	Node *head;
	Node *last;
	LinkedList();

	void InsertHead(T Element);

	void InsertLast(T Element);

	void InsertBtw(T Element, int index);

	T Search(T Element);

	void Display();

	T DeleteHead();

	T DeleteLast();

	T DeleteBtw(int index);

	int sum();
	int Length();
	~LinkedList()
	{
	}
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	last = NULL;
}

template <class T>
void LinkedList<T>::InsertHead(T Element)
{
	Node *t = new Node;
	if (head == NULL && last == NULL)
	{
		// if there are No Nodes in the LinkedList
		t->next = NULL;
		t->data = Element;
		head = t;
		last = t;
	}
	else
	{
		if (t == NULL)
		{
			cout << "Linked List is Full" << endl;
		}
		else
		{
			t->next = head;
			t->data = Element;
			head = t;
		}
	}
}

template <class T>
void LinkedList<T>::InsertLast(T Element)
{
	Node *t = new Node;
	if (head == NULL && last == NULL)
	{
		// if there are No Nodes in the LinkedList
		Node *t = new Node;
		t->next = NULL;
		t->data = Element;
		head = t;
		last = t;
	}
	else
	{
		if (t == NULL)
		{
			cout << "Linked List is Full" << endl;
		}
		else
		{
			t->data = Element;
			t->next = NULL;
			last->next = t;
			last = t;
		}
	}
}

template <class T>
void LinkedList<T>::InsertBtw(T Element, int index)
{

	Node *t = new Node;

	if (head == NULL && last == NULL)
	{
		// if there are No Nodes in the LinkedList
		t->next = NULL;
		t->data = Element;
		head = t;
		last = t;
	}
	else
	{
		if (t == NULL)
		{
			cout << "Linked List is Full" << endl;
		}
		else
		{
			int track = 0;
			Node *p = head;
			for (int i = 0; i < index - 1; i++)
			{
				p = p->next;
			}
			// while(p != NULL && track <= Length())){
			// 	p = p->next;
			// }
			// cout<<p->data<<endl;
			t->next = p->next;
			t->data = Element;
			p->next = t;
		}
	}
}

template <class T>
T LinkedList<T>::Search(T Element)
{
	Node *p = head;
	int i = 0;
	while (p != NULL)
	{
		if (p->data == Element)
		{
			return i;
		}
		i++;
		p = p->next;
	}
	return -1;
}

template <class T>
void LinkedList<T>::Display()
{
	Node *p = head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template <class T>
T LinkedList<T>::DeleteHead()
{
	T x = -1;
	if (head == NULL && last == NULL)
	{
		cout << "Linked List is Empty" << endl;
	}
	else
	{
		Node *p = head;
		head = head->next;
		x = p->data;
		delete p;
	}
	return x;
}

template <class T>
T LinkedList<T>::DeleteLast()
{
	T x = -1;
	Node *p = head;
	Node *q = NULL;

	while (p->next != NULL)
	{
		q = p;
		p = p->next;
	}

	last = q;
	last->next = NULL;
	x = p->data;
	delete p;
	return x;
}

template <class T>
T LinkedList<T>::DeleteBtw(int index)
{
	Node *q = NULL, *p = head;
	T x = -1;
	int i = 0;
	if (index == 1)
	{
		//we will delete first node
		q = head;
		head = head->next;
		delete q;
	}
	else
	{
		//we will delete other Node
		for (i = 0; i < (index - 1); i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}
	return x;
}

template <class T>
int LinkedList<T>::sum()
{
	int sum = 0;
	Node *p = head;
	while (p != NULL)
	{
		sum = sum + p->data;
		p = p->next;
	}
	return sum;
}

template <class T>
int LinkedList<T>::Length()
{
	Node *p = head;
	int length = 0;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}

//Operations on stack
//push
//pop
//peek
//Display
//Sum
template <class T>
class Stack
{
private:
	Node *Top;

public:
	Stack();
	void push(T Element);
	T pop();
	T peek(int pos);
	int isFull();
	int isEmpty();
	void Display();
	int stackTop();
	int Sum();
};

template <class T>
Stack<T>::Stack()
{
	Top = NULL;
}
template <class T>
void Stack<T>::push(T Element)
{
	struct Node *t = new Node;
	if (t == NULL)
	{
		cout << "Stack Overflow" << endl;
	}
	else
	{
		t->data = Element;
		t->next = Top;
		Top = t;
	}
}

template <class T>
int Stack<T>::stackTop()
{
	return Top->data;
}

template <class T>
T Stack<T>::pop()
{
	T x = -1;
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

template <class T>
T Stack<T>::peek(int pos)
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
template <class T>
int Stack<T>::isFull()
{
	//we will create a node and check if that node is
	//created and if it is not created then we dont have space in heap.
	struct Node *t = new Node;
	int x = t ? 0 : 1;
	return x;
}
template <class T>
int Stack<T>::isEmpty()
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

template <class T>
void Stack<T>::Display()
{
	struct Node *p = Top;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template <class T>
int Stack<T>::Sum()
{
	Node *p = Top;
	int sum = 0;
	while (p != NULL)
	{
		sum = sum + p->data;
		p = p->next;
	}
	return sum;
}

//      Queue(int size);
// 	~Queue();
// 	bool isFull();
// 	bool isEmpty();
// 	void enqueue(int x);
// 	T dequeue();
// 	void display();
template <class T>
class Queue
{
public:
	int size;
	int front;
	int rear;
	T *Q;

public:
	Queue(int size);
	bool isFull();
	bool isEmpty();
	void enqueue(T x);
	T dequeue();
	void display();
	~Queue()
	{
		delete[] Q;
		cout << "Queue class destructor Called" << endl;
	}
};

template <class T>
Queue<T>::Queue(int size)
{
	this->size = size;
	front = -1;
	rear = -1;
	Q = new int[size];
}

template <class T>
bool Queue<T>::isEmpty()
{
	if (front == rear)
	{
		return true;
	}
	return false;
}

template <class T>
bool Queue<T>::isFull()
{
	if (rear == size - 1)
	{
		return true;
	}
	return false;
}

template <class T>
void Queue<T>::enqueue(T x)
{
	if (isFull())
	{
		cout << "Queue Overflow" << endl;
	}
	else
	{
		rear++;
		Q[rear] = x;
	}
}

template <class T>
T Queue<T>::dequeue()
{
	T x = -1;
	if (isEmpty())
	{
		cout << "Queue Underflow" << endl;
	}
	else
	{
		front++;
		x = Q[front];
	}
	return x;
}

template <class T>
void Queue<T>::display()
{
	for (int i = front + 1; i <= rear; i++)
	{
		cout << Q[i] << flush;
		if (i < rear)
		{
			cout << " <- " << flush;
		}
	}
	cout << endl;
}

//To use Any Datasturcture just called the class and pass the constructor parameter ie..
//Array<DataType> array(sizeofArray);
//Array<int> array(10);
//to access the property of DataStructure ..ie array.Display();