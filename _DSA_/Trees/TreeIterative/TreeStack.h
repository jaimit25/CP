#include <iostream>
#include <stdlib.h>
#include "Queues.h"

using namespace std;
struct Stack
{
	int size;
	int top;
	struct Node **s;
};

void create(struct Stack *st)
{
	cout << "enter size of Stack" << endl;
	cin >> st->size;
	st->s = (struct Node**)malloc(st->size * sizeof(Node*));
	st->top = -1;
}

void Display(struct Stack st)
{
	int i;
	for (i = st.top; i >= 0; i--)
	{
		cout << st.s[i] << endl;
	}
	cout << "* * * *" << endl;
}

void push(struct Stack *st, Node *x)
{

	if (st->top == st->size - 1)
	{
		cout << "Stack Overflow" << endl;
	}
	else
	{
		st->top++;
		st->s[st->top] = x;
	}
}
Node* pop(struct Stack *st)
{
	Node *x = NULL;
	if (st->top == -1)
	{
		cout << "Stack Underflow" << endl;
	}
	else
	{

		x = st->s[st->top];
		st->top--;
	}
	return x;
}


int isFull(struct Stack st)
{
	if (st.top == st.size - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty(struct Stack st)
{
	if (st.top == -1)
	{
		return 1;
	}
	else
		return 0;
}

// Node* peek(struct Stack st, int pos)
// {
// 	int x = -1;
// 	if (st.top - pos + 1 < 0)
// 	{
// 		return -1;
// 	}
// 	else
// 	{
// 		return st.s[st.top - pos + 1];
// 	}
// }
// Node* stackTop(struct Stack st)
// {
// 	if (st.top == -1)
// 	{
// 		return -1;
// 	}
// 	return st->s[st.top];
// }
