//conversion of infix expression to postfix

#include<stdio.h>
#include<stdlib.h>

struct stack{
	int a[20];
	int top;
	int size;
};

void push(struct stack *s, char c)
{
	if(s->top==s->size-1)
		printf("stack is full\n");
	else
	{
		s->top++;
		s->a[s->top]=c;
	}
}

char pop(struct stack *s)
{
	char c;
	if(s->top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		c=s->a[s->top--];
		return c;
	}
}

char top(struct stack *s)
{
	if(s->top==0)
		return '('; 
	else
		return s->a[s->top];
}

int isempty(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int prior( char c)
{
	if(c=='(')
		return 0;
	else if(c=='^')
		return 1;
	else if(c=='+' || c=='-')
		return 2;
	else if(c=='*' || c=='/')
		return 3;
	else 
		return 4;
}


void main()
{
	char exp[20];
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	printf("enter expression: ");
	scanf("%s",exp);
	char *e;
	e=exp;
	s->top=0;
	s->size=20;
	while(*e!='\0')
	{
		if(*e=='(')
		{
			push(s,*e);
		}
		else if(*e=='+' || *e=='-' || *e=='*' || *e=='/' || *e=='^')
		{
			while(prior(top(s)) >= prior(*e))
			{
				printf("%c",pop(s));
			}
			push(s,*e);
		}
		else if(*e==')')
		{
			while(top(s)!='(')
			{
				printf("%c",pop(s));
			}
			pop(s);
		}
		else
		{
			printf("%c",*e);
		}
		e++;
	}
	while(!isempty(s))
	{
		printf("%c",pop(s));
	}
}

