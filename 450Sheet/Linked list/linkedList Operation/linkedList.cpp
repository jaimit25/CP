#include <iostream>
using namespace std;

class Node
{

public:
	int data;
	Node *next;
	Node()
	{
		next = NULL;
	}
};

class LinkedList
{
private:
	Node *first;

public:
	LinkedList();
	void display();
	void insert_start(int);
	void insert_btw(int, int);
	int getfirst();
	int deleteNode(int);
	int checkloop();
	Node *getfirstNode()
	{
		return first;
	}
};

LinkedList::LinkedList()
{
	first = NULL;
}

void LinkedList::display()
{
	Node *p = first;
	if (first == NULL)
	{
		cout << "Linked list is Empty" << endl;
	}
	else
	{
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void LinkedList::insert_start(int val)
{
	Node *t = new Node;
	if (first == NULL)
	{
		t->data = val;
		t->next = NULL;
		first = t;
	}
	else
	{
		t->data = val;
		t->next = first;
		first = t;
	}
}

void LinkedList::insert_btw(int index, int val)
{
	Node *t = new Node;
	Node *p = first;

	if (index == 0)
	{
		t->data = val;
		if (first == NULL)
		{
			t->next = NULL;
			first = t;
		}
		else
		{
			t->next = first;
			first = t;
		}
	}
	else
	{
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "Invalid Location" << endl;
		}
		else
		{
			t->data = val;
			t->next = p->next;
			p->next = t;
		}
	}
}
int LinkedList::getfirst()
{
	if (first == NULL)
	{
		return -1;
	}
	return first->data;
}

int LinkedList::deleteNode(int val)
{
	int x = -1;
	Node *p = first;
	Node *q;
	// p != NULL &&
	while (p->data != val)
	{
		q = p;
		p = p->next;
	}

	if (p == NULL)
	{
		cout << "Data not found" << endl;
	}
	else if (p->data == val)
	{
		if (p == first)
		{
			//first node
			first = first->next;
			x = p->data;
			delete p;
		}
		else
		{
			//not first node
			q->next = p->next;
			x = p->data;
			delete p;
		}
	}

	return x;
}

int LinkedList::checkloop()
{

	Node *fast_pointer;
	Node *slow_pointer;

	fast_pointer = slow_pointer = first;

	do
	{
		fast_pointer = fast_pointer->next;
		slow_pointer = slow_pointer->next;
		fast_pointer = fast_pointer ? fast_pointer->next : fast_pointer; //increasing speed of fast pointer
	} while (fast_pointer != slow_pointer && fast_pointer != NULL && slow_pointer != NULL);

	if(fast_pointer == slow_pointer) {
		return 1;
	}
	else{
		return -1;
	}

}

int main()
{

	LinkedList l;
	// l.insert_start(12);
	// l.insert_start(31);
	// l.insert_start(78);
	// l.insert_btw(1, 55);
	// l.display();
	// l.deleteNode(12);
	// l.display();
	// l.insert_btw(3, 99);
	// l.display();

	l.insert_start(12);
	l.insert_start(13);
	l.insert_start(14);
	l.insert_start(15);
	l.display();


	//creating a loop in linked list procedure
	Node *c = l.getfirstNode();
	// cout<<c->data<<endl;
	Node *t1, *t2;
	t1 = c->next->next;
	t2 = c->next->next->next;
	// cout<<t1->data<<endl; //pointing at 13
	// cout<<t2->data<<endl; //pointing at 12
	t2->next = t1; //created a loop
	// l.display();//this condition will cause continue running of loop

	//checking for loop in linked list 
	cout<<"Checking for loop in linked list :  "<<l.checkloop()<<endl;
	return 0;
}