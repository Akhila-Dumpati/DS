//implementation of stack

#include<stdio.h>
int push(int a[],int top,int sz)
{
	int ele;
	
	return top;
}
int pop(int a[],int top,int sz)
{
	
	return top;
}
void main()
{
	 int sz;
	printf("enter size of stack: ");
	scanf("%d",&sz);
	int a[sz],top=-1,op,ele;
	do
	{
		printf("1.PUSH \n 2.POP \n 3.EXIT\n");
		printf("enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
		 	case 1:
			{
				if(top==sz-1)
					printf("stack is full\n");
				else
				{
					top++;
					printf("enter element : ");
					scanf("%d",&ele);
					a[top]=ele;
				}
				break;
			}
			case 2:
			{
				if(top==-1)
					printf("stack is empty\n");
				else
				{
					printf("%d is popped",a[top]);
					top--;
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

	}while(op!=3);
}
