#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

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

int isbalance(char *exp)
{

	int i = 0;
	for (i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
		{
			push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			if (Top == NULL)
			{
				return 0;
			}
			pop();
		}
	}

	if (Top == NULL)
	{
		return 1;
	}
	return 0;
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '/' || x == '*')
	{
		return 0;
	}
	else
		return 1;
}

int pre(char x)
{
	//precedence
	if (x == '+' || x == '-')
	{
		return 1;
	}
	else if (x == '/' || x == '*')
		return 2;

	return 0;
}

char *convertInfixToPostfix(char *infix)
{
	int i = 0, j = 0;
	char *postfix;
	int len = strlen(infix);
	postfix = new char[(len + 2)];
	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}
		else
		{
			if (pre(infix[i]) > pre(Top->data))
			{
				push(infix[i++]);
			}
			else
			{
				postfix[j++] = pop();
			}
		}
	}
	while (Top != NULL)
	{
		postfix[j++] = pop();
		// Top = Top->next;
	}
	postfix[j] = '\0';
	return postfix;
}

int Evaluate(char *postfix)
{
	int i = 0, x1, x2, r;
	for (i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperand(postfix[i]))
		{
			push(postfix[i]-'0');

		}
		else{
			x2 = pop();
			x1 = pop();
			switch (postfix[i]){
				case '+': r = x1+x2;  break;
				case '-': r = x1-x2;  break;
				case '/': r = x1/x2;  break;
				case '*': r = x1*x2;  break;
			}
			push(r);
		}
	}
	return Top->data;
}
int main() 
{
	// char *infix = "a+b*c";
	// push('#');
	// char *postfix = convertInfixToPostfix(infix);
	// //initially stack is empty so  push '#' so we dont get error

	// printf("%s \n",postfix);

	char *postfix = "234*+82/-";
	int ans = Evaluate(postfix);
	cout << Evaluate(postfix) << endl;

	return 0;
}