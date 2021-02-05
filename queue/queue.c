//implementation of queue

#include<stdio.h>

int main()
{
	int size,front,rear,element,option;
	front=-1;
	rear=-1;
	printf("enter the size of queue: ");
	scanf("%d",&size);
	int a[size];
	do
	{
		printf("1.enqueue\n2.dequeue\n3.exit\n");
		printf("enter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			{
				if(rear==size-1)
					printf("queue is full\n");
				else
				{
					rear++;
					printf("enter element: ");
					scanf("%d",&element);
					a[rear]=element;
				}
				break;
			}
			case 2:
			{
				if(front==rear)
					printf("queue is empty\n");
				else
				{
					front++;
					printf("dequeued element is %d\n",a[front]);
				}
				break;
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
