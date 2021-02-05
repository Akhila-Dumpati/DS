#include<stdio.h>
#include<stdlib.h>

struct node
{
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
	}
	else
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->e=ele;
		temp->next=head;
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
		printf("%d,is popped\n",head->e);
		head=head->next;
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
