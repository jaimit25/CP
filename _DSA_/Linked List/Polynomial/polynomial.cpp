#include <iostream>
#include <stdlib.h>
#include<cmath>

using namespace std;

struct Node
{
	int coeff;
	int exp;
	struct Node *next;
} *poly = NULL;

void create()
{
	struct Node *t, *last;
	int num, i;
	cout << "Enter Number of Terms : " << endl;
	cin >> num;
	cout << "Enter each terms with coff and Exponent : " << endl;
	for (i = 0; i < num; i++)
	{
		t = new Node;
		cin >> t->coeff >> t->exp;
		t->next = NULL;
		if (poly == NULL)
		{
			poly = last = t;
		}
		else
		{
			last->next = t;
			last = t;
		}
	}
}

void Display(struct Node *p)
{
	while (p != NULL)
	{
		cout << p->coeff << "X"
		     << "^" << p->exp << " + ";
		p = p->next;
	}
	cout << endl;
}

long Eval(struct Node *p, int x)
{
	long val=0;
	while (p != NULL)
	{
		val +=  p->coeff*pow(x,p->exp);
		p = p->next;
	}
	return val;
}

int main()
{
	create();
	Display(poly);
	cout<<Eval(poly,1)<<endl; //we will give sum of coefficients
	return 0;
}
