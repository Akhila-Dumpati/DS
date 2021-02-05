//implementation of stack using structure and functions

#include<stdio.h>
struct stack{
	int a[5];
	int top;
	int size;
};
struct stack push(struct stack s)
{	
	if(s.top==s.size-1)
		printf("stack is full\n");
	else
	{
		s.top++;
		printf("enter element to insert: ");
		scanf("%d",&s.a[s.top]);
	}
	return s;
}
struct stack pop(struct stack s)
{
	if(s.top==-1)
		printf("stack is empty\n");
	else
	{
		printf("%d is popped\n",s.a[s.top]);
		s.top--;
	}
	return s;
}
void main()
{
	struct stack s;
	s.size=5;
	s.top=-1;
	int op,ele;
do
	{
		printf(" 1.PUSH \n 2.POP \n 3.EXIT\n");
		printf("enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
		 	case 1:
			{
				s=push(s);
				break;	
			}
			case 2:
			{
				s=pop(s);
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
