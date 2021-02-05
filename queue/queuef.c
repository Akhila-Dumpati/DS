//implementation of queue using functions
#include<stdio.h>

int enqueue(int a[], int rear,int size)
{	
	int element;
	if(rear==size-1)
		printf("queue is full\n");
	else
	{
		rear++;
		printf("enter element: ");
		scanf("%d",&element);
		a[rear]=element;
	}
	return rear;
}

int dequeue(int a[],int front,int rear)
{
	if(front==rear)
		printf("queue is empty\n");
	else
	{
		front++;
		printf("dequeued element is %d \n",a[front]);
	}
	return front;
}	 
int main()
{
	int size,option,rear,front;
	rear=-1;
	front=-1;
	printf("enter size of queue: ");
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
				rear=enqueue(a,rear,size);
				break;
			}
			case 2:
			{
				front=dequeue(a,front,rear);
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
		

