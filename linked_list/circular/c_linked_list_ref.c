#include<stdio.h>
#include<stdlib.h>

struct node
{
	int e;
	struct node *next;
};

void insert_beg(struct node **head)
{
	struct node *temp,*temp1=*head;
	int ele;
	printf("enter element to insert: ");
	scanf("%d",&ele);
	if(*head==NULL)
	{
		*head=(struct node*)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=*head;
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->e=ele;
		temp->next=*head;
		while(temp1->next!=*head)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		*head=temp;
		
	}
}

void insert_end(struct node **head)
{
	struct node *temp=*head,*nn;
	int ele;
	printf("enter element to insert: ");
	scanf("%d",&ele);
	if(*head==NULL)
	{
		*head=(struct node*)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=*head;
	}
	else
	{
		while(temp->next!=*head)
		{
			temp=temp->next;
		}
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		nn->next=*head;
		temp->next=nn;
	}
}

void rem_ele(struct node **head)
{
	struct node *temp=*head,*temp1=*head;
	int ele,f=0;
	printf("enter element to remove: ");
	scanf("%d",&ele);
	if(*head!=NULL)
	{
		if((*head)->e==ele)
		{
			while(temp1->next!=*head)
			{
				temp1=temp1->next;
			}
			if((*head)->next!=*head)
			{
				*head=(*head)->next;
				temp1->next=*head;
			}
			else
			{
				*head=NULL;
			}
		}
		else
		{
			while(temp->next!=*head)
			{
				if(temp->e==ele)
				{
					f=1;
					break;
				}
				else
				{
					temp=temp->next;
				}
			}
			if(temp->next!=*head && f==1)
			{
				temp1=*head;
				while(temp1->next!=temp)
				{
					temp1=temp1->next;
				}	
				temp1->next=temp->next;
			}
			else
			{
				if(temp->e==ele && f==0)
				{
					temp1=*head;
					while(temp1->next!=temp)
					{
						temp1=temp1->next;
					}	
					temp1->next=temp->next;
				}
				else
				{
					printf("removing is not possible\n");
				}
			}
		}
	}
	else
	{
		printf("removing is not possible\n");
	}
}

void searching(struct node **head)
{
	struct node *temp=*head;
	int ele,f=0;
	if(*head==NULL)
	{
		printf("list is empty,searching is not possible\n");
	}
	else
	{
		printf("enter element to search: ");
		scanf("%d",&ele);
		while(temp->next!=*head)
		{
			if(temp->e==ele)
			{
				f=1;
				break;
			}
			else
			{
				temp=temp->next;
			}
		}
		if(temp->e==ele)
		{
			f=1;
		}
		if(f==1)
		{
			printf("found\n");
		}
		else
		{
			printf("not found\n");
		}
	}
}

void display(struct node **head)
{
	struct node *temp=*head;
	if(*head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(temp->next!=*head)
		{
			printf("%d ",temp->e);
			temp=temp->next;
		}
		printf("%d\n",temp->e);
	}
}

void main()
{
	struct node *head=NULL;
	int op;
	printf("1.Insertion at beginning\n2.Insertion at end\n3.Removing an element\n4.searching elemnt\n5.display elements\n6.exit\n");
	do
	{
		printf("enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				insert_beg(&head);
				break;
			}
			case 2:
			{
				insert_end(&head);
				break;
			}
			case 3:
			{
				rem_ele(&head);
				break;
			}
			case 4:
			{
				searching(&head);
				break;
			}
			case 5:
			{
				display(&head);
				break;
			}
			case 6:
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
	}while(op!=6);
}

