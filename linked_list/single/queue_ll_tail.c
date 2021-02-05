#include<stdio.h>
#include<stdlib.h>

struct node
{
	int e;
	struct node *next;
};

struct node* enqueue(struct node *head)
{
	struct node *temp=head, *temp1;
	int ele;
	printf("Enter element to insert: ");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->e=ele;
		head->next=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=(struct node*)malloc(sizeof(struct node));
		temp1->e=ele;
		temp1->next=NULL;
		temp->next=temp1;
	}
	return head;		
}

struct node* dequeue(struct node *head)
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("Removing is not possible\n");
	}
	else
	{
		printf("%d is popped\n",head->e);
		head=head->next;
	}
	return head;
}

void main()
{
	struct node *head=NULL;
	int op;
	printf("1.PUSH\n2.POP\n3.EXIT\n");
	do{
		printf("Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				head=enqueue(head);
				break;
			}
			case 2:
			{
				head=dequeue(head);
				break;
			}
			case 3:
			{
				printf("THANK YOU\n");
				break;
			}
			default:
			{
				printf("Invalid option\n");
				break;
			}
		}
	}while(op!=3);
}
