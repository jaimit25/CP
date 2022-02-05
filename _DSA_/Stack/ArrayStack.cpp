#include <iostream>
#include <stdlib.h>

using namespace std;

struct Stack
{
	int size;
	int top;
	int *s;
};

void create(struct Stack *st)
{
	cout << "enter size of Stack" << endl;
	cin >> st->size;
	st->s = (int *)malloc(st->size * sizeof(int));
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

void push(struct Stack *st, int x)
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
int pop(struct Stack *st)
{
	int x = -1;
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

int peek(struct Stack st, int pos)
{
	int x = -1;
	if (st.top - pos + 1 < 0)
	{
		return -1;
	}
	else
	{
		return st.s[st.top - pos + 1];
	}
}
int stackTop(struct Stack st)
{
	if (st.top == -1)
	{
		return -1;
	}
	return st.s[st.top];
}
int main()
{
	struct Stack st;
	create(&st);
	push(&st, 12);
	push(&st, 21);
	push(&st, 43);
	push(&st, 31);
	push(&st, 53);
	Display(st);
	cout << "Full: " << isFull(st) << endl;
	pop(&st);
	Display(st);
	cout << "Empty: " << isEmpty(st) << endl;

	return 0;
}
