//implementation of queue using structure and array pointer
#include<stdio.h>
#include<stdlib.h>

struct queue{
	int *a;
	int rear;
	int front;
	int size;
};

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
				if(q->rear==q->size-1)
					printf("stack is full\n");
				else
				{
					q->rear++;
					printf("enter element to insert: ");
					scanf("%d",&element);
					q->a[q->rear]=element;
				}
				break;
			}
			case 2:
			{
				if(q->front==q->rear)
					printf("queue is empty\n");
				else
				{
					q->front++;
					printf("dequeued element is %d\n",q->a[q->front]);
				}
				break;
			}
			case 3:
			{
				printf("Thank you\n");
				break;
			}
			default:
			{
				printf("invalid input\n");
				break;
			}
		}
	}while(option!=3);
}
	
