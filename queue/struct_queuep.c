//implementation of queue using structure pointer
#include<stdio.h>
#include<stdlib.h>

struct queue{
	int a[10];
	int rear;
	int front;
	int size;
};

int main()
{
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	q->rear=-1;
	q->front=-1;
	q->size=10;
	int option,element;
	do
	{
		printf("1.enqueue\n2.dequeue\n3.exit\n");
		printf("enter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			{
				if(q->rear==q->size-1)
					printf("queue is full\n");
				else
				{
					q->rear++;
					printf("enter element: ");
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
			}
			case 3:
				break;
			default:
			{
				printf("invalid option\n");
				break;
			}
		}

	}while(option!=3);
}	
		

