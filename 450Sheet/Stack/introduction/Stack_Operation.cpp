#include <iostream>
using namespace std;

class Stack
{
private:
	int *A;
	int i;

public:
	Stack();
	void push(int);
	int pop();
	int peek();
	void display();
};

void Stack::display()
{
	for (int j = i - 1; j >= 0; j--)
	{
		cout << A[j] << " ";
	}
	cout << endl;
}

Stack::Stack()
{
	i = 0;
	cout << "Size of Stack is : 10 " << endl;
	A = new int[10];
}

void Stack::push(int val)
{
	if (i < 10)
	{
		A[i] = val;
		i++;
	}
	else
	{
		cout << "Stack Overflow" << endl;
	}
}
int Stack::pop()
{
	int x;
	if (i == -1)
	{
		cout << "Stack underflow" << endl;
	}
	else
	{
		x = A[i - 1];
		i--;
	}
	return x;
}

int Stack::peek()
{
	if (i == -1)
	{
		return -1;
	}
	return A[i - 1];
}

int main()
{

	Stack s;
	s.push(12);
	s.push(23);
	s.push(45);
	s.push(89);
	s.push(58);
	s.push(90);
	s.display();
	s.pop();
	s.display();
	cout << "popping Element : " << s.pop() << endl;
	s.display();
	cout<<"peeking element from Stack : "<<s.peek()<<endl;

	return 0;
}