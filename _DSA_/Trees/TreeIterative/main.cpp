#include <stdio.h>
#include <stdlib.h>
#include "TreeStack.h"

struct Node *root = NULL;
void Treecreate()
{
	struct Node *p, *t;
	int x;
	struct Queue q;
	create(&q, 100);

	printf("Enter root value ");
	scanf("%d", &x);
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);

	while (!isEmpty(q))
	{
		p = dequeue(&q);
		printf("enter left child of %d ", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct
							 Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);
		}
		printf("enter right child of %d ", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct
							 Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q, t);
		}
	}
}
void Preorder(struct Node *p)
{
	if (p)
	{
		printf("%d ", p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}
void Inorder(struct Node *p)
{
	if (p)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}
void Postorder(struct Node *p)
{
	if (p)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d ", p->data);
	}
}

void IterativePreorder(struct Node *p)
{
	struct Stack stk;
	create(&stk);

	while (p || !isEmpty(stk)){
		if (p)
		{
			cout<<p->data<<" ";
			push(&stk, p);
			p = p->lchild;
		}
		else{
			p = pop(&stk);
			p = p->rchild;
		}
	}

}	
void IterativeInorder(struct Node *p)
{
	struct Stack stk;
	create(&stk);

	while (p || !isEmpty(stk)){
		if (p)
		{
			push(&stk, p);
			p = p->lchild;
		}
		else{
			p = pop(&stk);
			cout<<p->data<<" ";
			p = p->rchild;
		}
	}

}	

//error Not Resolved
// void IterativePostorder(struct Node *p)
// {
// 	struct Stack stk;
// 	long int temp;
// 	create(&stk);

// 	while (p || !isEmpty(stk)){
// 		if (p)
// 		{
// 			push(&stk, p);
// 			p = p->lchild;
// 		}
// 		else{
// 			temp = (int)pop(&stk);
// 			if(temp>0){
// 				push(&stk, (Node*)-temp);
// 				t = (Node *)(temp->rchild);
// 			}
// 			else{
// 				cout<<(Node*)temp->data<<" ";
// 				p= NULL;
// 			}
// 		}
// 	}

// }	

int main()
{
	Treecreate();
	IterativePreorder(root);
	

	return 0;
}