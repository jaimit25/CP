#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Element
{
	int i;
	int j;
	int x;
};

struct Sparse
{
	int m;
	int n;
	int num; //number of Non zero Elements
	struct Element *ele;
};

void create(struct Sparse *s)
{
	int i;
	printf("Enter Dimension m and n : \n");
	scanf("%d %d", &s->m, &s->n);
	printf("Enter Number of non Zero elements : \n ");
	scanf("%d", &(s->num)); //we are passing address of our struct to scanf as parameter
	s->ele = (struct Element *)malloc(sizeof(struct Element));
	printf("Enter The Elements : \n");
	for (i = 0; i < s->num; i++)
	{
		scanf("%d %d %d", &s->ele[i].i,
		      &s->ele[i].j,
		      &s->ele[i].x);
	}
}

void Display(struct Sparse s)
{
	int i , j ,k = 0;
	for (i = 0; i < s.m; i++)
	{
		for (j = 0; j < s.n; j++)
		{
			if( i == s.ele[k].i && j == s.ele[k].j){
				printf("%d" , s.ele[k++].x); //increment k for next element
			}
			else{
				printf(" 0");
			}
		}
		printf("\n");
	}
}

int main()
{

	struct Sparse s;
	create(&s);
	Display(s);
	return 0;
}