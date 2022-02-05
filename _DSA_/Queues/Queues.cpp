#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
};

void create(struct Queue *q, int size)
{
	q->size = size;
	q->front = q->rear = -1;
	q->Q = (int *)malloc(q->size * sizeof(int));
}

void Enqueue(struct Queue *q, int x)
{
	//first we will check if Queue is Full
	if (q->rear == (q->size - 1))
	{
		cout << "Queue is Full" << endl;
	}
	else
	{
		q->rear++;
		q->Q[q->rear] = x;
	}
}

int Dequeue(struct Queue *q)
{
	int x = -1;

	if (q->front == q->rear)
		printf("Queue is Empty\n");
	else
	{
		q->front++;
		x = q->Q[q->front];
	}
	return x;
}

void Display(struct Queue q)
{
	int i;

	for (i = q.front + 1; i <= q.rear; i++)
		printf("%d ", q.Q[i]);
	printf("\n");
}

int main()
{
	int sz;
	struct Queue q;
	create(&q, 5);
	// cout << "Enter Size of Queue" << endl;
	// cin >> sz;
	// q.size = sz;
	// q.Q = new int[sz];
	// q.front = q.rear = -1;

	Enqueue(&q, 12);
	Enqueue(&q, 15);
	Enqueue(&q, 17);
	Enqueue(&q, 18);
	Enqueue(&q, 19);
	Display(q);
	cout << "Deleting Element : " << Dequeue(&q) << endl;
	cout << "Deleting Element : " << Dequeue(&q) << endl;
	Display(q);

	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// struct Queue
// {
// 	int size;
// 	int front;
// 	int rear;
// 	int *Q;
// };
// void create(struct Queue *q, int size)
// {
// 	q->size = size;
// 	q->front = q->rear = -1;
// 	q->Q = (int *)malloc(q->size * sizeof(int));
// }
// void enqueue(struct Queue *q, int x)
// {
// 	if (q->rear == q->size - 1)
// 		printf("Queue is Full");
// 	else
// 	{
// 		q->rear++;
// 		q->Q[q->rear] = x;
// 	}
// }
// int dequeue(struct Queue *q)
// {
// 	int x = -1;

// 	if (q->front == q->rear)
// 		printf("Queue is Empty\n");
// 	else
// 	{
// 		q->front++;
// 		x = q->Q[q->front];
// 	}
// 	return x;
// }
// void Display(struct Queue q)
// {
// 	int i;

// 	for (i = q.front + 1; i <= q.rear; i++)
// 		printf("%d ", q.Q[i]);
// 	printf("\n");
// }
// int main()
// {
// 	struct Queue q;
// 	create(&q, 5);

// 	enqueue(&q, 10);
// 	enqueue(&q, 20);
// 	enqueue(&q, 30);
// 	Display(q);

// 	printf("%d ", dequeue(&q));
// 	return 0;
// }