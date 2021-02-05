//implementation of stack using double linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int e;
	struct node *next;
};

struct node* push(struct node *head)
{
	int ele;
	printf("enter element to insert: ");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->e=ele;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->e=ele;
		temp->prev=NULL;
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	return head;
}

struct node* pop(struct node *head)
{
	if(head==NULL)
	{
		printf("Removing is not possible\n");
	}
	else
	{
		printf("%d is popped\n",head->e);
		if(head->next!=NULL)
		{
			head=head->next;
			head->prev=NULL;
		}
		else
			head=NULL;
	}
	return head;
}
void main()
{
	struct node *head=NULL;
	int op;
	printf("1.PUSH\n2.POP\n3.EXIT\n");
	do
	{
		printf("Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				head=push(head);
				break;
			}
			case 2:
			{
				head=pop(head);
				break;
			}
			case 3:
			{
				printf("THANK YOU\n");
				break;
			}
			default:
			{
				break;
			}
		}
	}while(op!=3);		
}
