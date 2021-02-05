//implementation of stack using structure
#include<stdio.h>
struct stack{
	int a[5];
	int top;
	int size;
};

void main()
{
	struct stack s;
	s.size=5;
	s.top=-1;
	int op,ele;
do
	{
		printf("1.PUSH \n 2.POP \n 3.EXIT\n");
		printf("enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
		 	case 1:
			{
				if(s.top==s.size-1)
					printf("stack is full\n");
				else
				{
					s.top++;
					printf("enter element: ");	
					scanf("%d",&ele);
					s.a[s.top]=ele;
				}
				break;	
			}
			case 2:
			{
				if(s.top==-1)
					printf("stack is empty\n");
				else
				{
					ele=s.a[s.top];
					printf("%d is popped\n",ele);
					s.top--;
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
