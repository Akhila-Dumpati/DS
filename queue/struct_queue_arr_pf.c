//implementation of queue using structure array pointer and functions
#include<stdio.h>
#include<stdlib.h>

struct queue{
	int *a;
	int rear;
	int front;
	int size;
};

void enqueue(struct queue *q,int element)
{
	if(q->rear==q->size-1)
		printf("queue is full\n");
	else
	{
		q->rear++;
		q->a[q->rear]=element;
	}
}

int dequeue(struct queue *q)
{
	if(q->front==q->rear)
	{
		printf("queue is empty\n");
		return 0;
	}
	else
	{
		q->front++;
		int element=q->a[q->front];
		return element;
	}
}

int main()
{
	struct queue *q;
	int option,element,n;
	printf("enter size of queue: ");
	scanf("%d",&n);
	q=(struct queue*)malloc(sizeof(struct queue));
	q->a=(int *)malloc(n*sizeof(int));
	q->rear=-1;
	q->front=-1;
	q->size=n;
	do
	{
		printf("1.enqueue\n2.dequeue\n3.exit\nenter your choice :");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			{
				printf("enter element to insert: ");
				scanf("%d",&element);
				enqueue(q,element);
				break;
			}
			case 2:
			{
				element=dequeue(q);
				printf("dequeued element is %d\n",element);
				break;
			}
			case 3:
			{
				printf("Thank you\n");
				break;
			}
			default:
			{
				printf("invalid input");
				break;
			}
		}
	}while(option!=3);
}
	
