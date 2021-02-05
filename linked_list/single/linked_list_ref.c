#include<stdio.h>
#include<stdlib.h>

struct node
{
	int e;
	struct node *next;
};

void head_insertion(struct node **head)
{
	struct node *temp;
	int ele;
	printf("enter element to insert: ");
	scanf("%d",&ele);
	if(*head==NULL)
	{
		*head=(struct node*)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=NULL;
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->e=ele;
		temp->next=*head;
		*head=temp;
	}
}

void tail_insertion(struct node **head)
{
	struct node *temp=*head,*temp1;
	int ele;
	printf("enter element: ");
	scanf("%d",&ele);
	if(*head==NULL)
	{
		*head=(struct node*)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=NULL;
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
}

void middle_insertion(struct node **head)
{
	struct node *temp=*head,*temp1;
	int ele,pos,c=0;
	printf("Enter element: ");
	scanf("%d",&ele);
	if(*head==NULL)
	{
		*head=(struct node*)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=NULL;
	}
	else if((*head)->next==NULL)
	{
		temp1=(struct node*)malloc(sizeof(struct node));
		temp1->e=ele;
		temp1->next=NULL;
		(*head)->next=temp1;
	}
	else
	{
		while(temp!=NULL)
		{
			temp=temp->next;
			c++;
		}
		pos=(c/2)-1;
		c=0; temp=*head;
		while(c!=pos)
		{
			temp=temp->next;
			c++;
		}
		temp1=(struct node*)malloc(sizeof(struct node));
		temp1->e=ele;
		temp1->next=temp->next;
		temp->next=temp1;
	}
}

void pos_insertion(struct node **head)
{
	struct node *temp=*head,*temp1;
	int ele,pos,c=1,len=0;
	printf("Enter position to insert: ");
	scanf("%d",&pos);
	while(temp!=NULL)
	{
		temp=temp->next;
		len++;
	}
	if(len<pos || head==NULL)
	{
		printf("Insertion is not possible\n");
	}
	else
	{
		printf("Enter element: ");
		scanf("%d",&ele);
		temp1=(struct node*)malloc(sizeof(struct node));
		if(pos==1)
		{
			temp1->e=ele;
			temp1->next=*head;
			*head=temp1;
		}
		else if(pos==2)
		{
			temp1->e=ele;
			temp1->next=(*head)->next;
			(*head)->next=temp1;
		}
		else
		{
			temp=*head;
			while(c<pos-1)
			{
				temp=temp->next;
				c++;
			}
			temp1->e=ele;
			temp1->next=temp->next;
			temp->next=temp1;
		}
	}
}

void searching(struct node **head)
{
	struct node *temp=*head;
	int f=0,ele;
	printf("enter element to search: ");
	scanf("%d",&ele);
	while(temp!=NULL)
	{
		if(temp->e==ele)
		{
			f=1;
			break;
		}
		else
			temp=temp->next;
	}
	if(f==1)
		printf("%d is found\n",ele);
	else
		printf("%d is not found\n",ele);
}

void rem_element(struct node **head)
{
	struct node *temp=*head;
	int ele,f=0;
	printf("enter element: ");
	scanf("%d",&ele);
	if(temp==NULL)
	{
		printf("removing is not possible:\n");
	}
	else
	{
		while(temp!=NULL)
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
		if(f==1)
		{
			if((*head)->e==ele)
			{
				*head=(*head)->next;
			}
			else
			{
			struct node *temp1=*head;
			while(temp1->next!=temp)
			{
				temp1=temp1->next;
			}
				temp1->next=temp->next;
			}
		}
		else
			printf("deletion is not possible\n");
	}
}

void rem_position(struct node **head)
{
	struct node *temp=*head;
	int pos,c=0;
	printf("enter position: ");
	scanf("%d",&pos);
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	if(pos>c)
	{
		printf("deletion at given position is not possible\n");
	}
	else
	{
		if(pos==1)
		{
			*head=(*head)->next;
		}
		else if(pos==c)
		{
			temp=*head;
			while(temp->next->next!=NULL)
				temp=temp->next;
			temp->next=NULL;
		}
		else
		{
			temp=*head;
			c=1;
			while(c<pos-1)
			{
				temp=temp->next;
				c++;
			}
			temp->next=temp->next->next;
		}
	}	
}
void rem_before(struct node **head)
{
	struct node *temp=*head;
	int ele,f=0;
	if(temp==NULL)
		printf("Linkedlist is empty\n");
	else
	{
		printf("enter element: ");
		scanf("%d",&ele);
		while(temp!=NULL)
		{
			if(temp->e==ele)
			{
				f=1;
				break;
			}
			else
				temp=temp->next;
		}
		if(f==1)
		{	
			if((*head)->e==ele)
				printf("removing is not possible\n");
			else if(((*head)->next)->e==ele)
				*head=(*head)->next;
			else
			{
				struct node *temp1=*head;
				while(temp1->next->next!=temp)
				{
					temp1=temp1->next;
				}
				temp1->next=temp1->next->next;
			}
		}
		else
		{
			printf("removing is not possible\n");
		}
	}
}
void rem_after(struct node **head)
{
	struct node *temp=*head;
	int ele,f=0;
	if(temp==NULL)
		printf("removing is not possible\n");
	else
	{
		printf("enter element: ");
		scanf("%d",&ele);
		while(temp!=NULL)
		{
			if(temp->e==ele)
			{
				f=1;
				break;
			}
			else
				temp=temp->next;
		}
		if(f==1)
		{
			if(temp->next==NULL)
				printf("removing is not possible\n");
			else
				temp->next=temp->next->next;
		}
		else
		{
			printf("removing is not possible\n");
		}
	}
}

void display(struct node **head)
{
	struct node *temp=*head;
	printf("Elements  :");
	while(temp!=NULL)
	{
		printf("%d ",temp->e);
		temp=temp->next;
	}
	printf("\n");
}
	
void main()
{
	struct node *head=NULL;
	int op;
	printf("1.Insertion at head\n2.Insertion at tail\n3.Insertion at middle\n4.Insertion at given position\n5.Searching given element\n6.Removing given element\n7.Removing element at given position\n8.Removing element before given element\n9.Removing element after given element\n10.Display elements in linkedlist\n11.Exit\n\n");
	do
	{
		printf("enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				head_insertion(&head);
				break;
			}
			case 2:
			{
				tail_insertion(&head);
				break;
			}
			case 3:
			{
				middle_insertion(&head);
				break;
			}
			case 4:
			{
				pos_insertion(&head);
				break;
			}
			case 5:
			{
				searching(&head);
				break;
			}
			case 6:
			{
				rem_element(&head);
				break;
			}
			case 7:
			{
				rem_position(&head);
				break;
			}
			case 8:
			{
				rem_before(&head);
				break;
			}
			case 9:
			{
				rem_after(&head);
				break;
			}
			case 10:
			{
				display(&head);
				break;
			}
			case 11:
			{
				printf("THANK YOU\n");
				break;
			}
			default:
			{
				printf("enter correct option\n");
				break;
			}
		}
	}while(op!=11);
}
