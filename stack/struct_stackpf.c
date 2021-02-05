//implementation of stack using structure ,pointer and functions

#include<stdio.h>
#include<stdlib.h>
struct stack{
	int a[5];
	int top;
	int size;
};
void push(struct stack *s,int ele)
{
	if(s->top==s->size-1)
		printf("stack is full\n");
	else
	{
		s->top++;
		s->a[s->top]=ele;
	}
}
int pop(struct stack *s)
{
	if(s->top==-1)
	{
		printf("stack is empty\n");
		return 0;
	}
	else
	{
		int ele=s->a[s->top];
		s->top--;
		return ele;
	}
}
void main()
{
	struct stack *s;
	s=(struct stack *) malloc(sizeof(struct stack));
	s->size=5;
	s->top=-1;
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
				printf("enter element to insert: ");	
				scanf("%d",&ele);
				push(s,ele);
				break;	
			}
			case 2:
			{
				ele=pop(s);
				printf("%d is popped\n",ele);
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
