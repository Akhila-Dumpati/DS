#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *prev;
	int e;
	struct node *next;
};

struct node* head_insertion(struct node *head)
{
	struct node *temp=head;
	int ele;
	printf("enter element: ");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->prev=NULL;
		head->e=ele;
		head->next=NULL;
	}
	else
	{
		temp=(struct node *) malloc(sizeof(struct node));
		temp->prev=NULL;
		temp->e=ele;
		temp->next=head;
		head=temp;
	}
	return head;
}

struct node* tail_insertion(struct node *head)
{
	struct node *temp=head,*temp1;
	int ele;
	printf("enter element: ");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->prev=NULL;
		head->e=ele;
		head->next=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=(struct node *) malloc(sizeof(struct node));
		temp1->prev=temp;
		temp1->e=ele;
		temp1->next=NULL;
		temp->next=temp1;
	}
	return head;
}

struct node* middle_insertion(struct node *head)
{
	struct node *temp=head,*temp1;
	int ele,c=0,pos;
	printf("enter element: ");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->prev=NULL;
		head->e=ele;
		head->next=NULL;
	}
	else if(head->next==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->prev=head;
		temp->e=ele;
		temp->next=NULL;
		head->next=temp;
	}
	else
	{
		while(temp!=NULL)
		{
			c++;
			temp=temp->next;
		}
		pos=(c/2);
		c=1;
		temp=head;
		while(c!=pos)
		{
			temp=temp->next;
			c++;
		}
		temp1=(struct node*)malloc(sizeof(struct node));
		temp1->prev=temp;
		temp1->e=ele;
		temp1->next=temp->next;
		temp->next=temp1;
	}
	return head;
}

struct node* pos_insertion(struct node *head)
{
	struct node *temp=head,*temp1;
	int ele,c=0,pos;
	printf("enter position (from 1): ");
	scanf("%d",&pos);
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	temp=head;
	if( c>=pos && temp!=NULL)
	{
		printf("enter element: ");
		scanf("%d",&ele);
		c=1;
		while(c!=pos-1)
		{
			temp=temp->next;
			c++;
		}
		temp1=(struct node*)malloc(sizeof(struct node));
		temp1->prev=temp;
		temp1->e=ele;
		temp1->next=temp->next;
		temp->next=temp1;
	}
	else
	{
		printf("insertion is not possible at given position\n");
	}
	return head;
}

void searching(struct node *head)
{
	struct node *temp=head;
	int ele, f=0;
	printf("enter element to search :");
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

struct node* rem_element(struct node *head)
{
	struct node *temp=head,*temp1;
	int ele,f=0;
	printf("enter element to remove :");
	scanf("%d",&ele);
	while(temp!=NULL)
	{
		if(temp->e==ele)
		{
			if(head->e==ele)
			{
				head=head->next;
				head->next->prev=NULL;
			}
			else if(temp->next==NULL)
			{
				temp->prev->next=NULL;
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
			}
			f=1;
			break;
		}
		else
			temp=temp->next;
	}
	if(f==0)
	{
		printf("removing is not possible\n");
	}
	return head;
}

struct node* rem_position(struct node *head)
{
	struct node *temp=head->next,*temp1=head;
	int pos,c=1;
	printf("enter position: ");
	scanf("%d",&pos);
	if(head==NULL || pos<=0)
	{
		printf("removing is not possible\n");
	}
	else
	{
		if(pos==1)
		{
			head=head->next;
		}
		else
		{
			while(c<pos-1 && temp!=NULL)
			{
				temp=temp->next;
				temp1=temp1->next;
				c++;
			}
			temp1->next=temp->next;
			temp->next->prev=temp->prev;
		}
	}
	return head;
}

struct node* rem_before(struct node *head)
{
	struct node *temp=head;
	int ele,f=0;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		printf("enter element: ");
		scanf("%d",&ele);
		if(temp->e==ele)
		{
			printf("There is no element before given element\n");
			f=1;
		}
		else if(temp->next->e=ele)
		{
			temp->next->prev=head;
			head=temp->next;
			f=1;
		}
		else
		{
			while(temp!=NULL)
			{
				if(temp->e==ele)
				{
					temp->prev=temp->prev->prev;
					temp->prev->next=temp;
					f=1;
					break;
				}
				else
				temp=temp->next;
			}
		}
		if(f==0)
		{
			printf("given elemnt is not there in list\n");
		}
	}
	return  head;
}

void rem_after(struct node *head)
{
	struct node *temp=head;
	int ele,f=0;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		printf("enter element: ");
		scanf("%d",&ele);
		while(temp!=NULL)
		{
			if(temp->e==ele)
			{
				if(temp->next==NULL)
				{
					printf("There is no element after given element\n");
				}
				else if(temp->next->next==NULL)
				{
					temp->next=NULL;
				}
				else
				{
					temp->next=temp->next->next;
					temp->next->next->prev=temp;
				}
				f=1;
				break;
			}
			temp=temp->next;
		}
		if(f==0)
		{
			printf("given elemnt is not there in list\n");
		}
	}
}

void display(struct node *head)
{
	struct node *temp=head;
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->e);
			temp=temp->next;
		}
		printf("\n");
	}
}

void main()
{
	struct node *head=NULL;
	int op;
	printf("1.Insertion at head\n2.Insertion at tail\n3.Insertion at middle\n4.Insertion at given position\n5.Searching given element\n6.Removing given element\n7.Removing element at given position\n8.Removing element before given element\n9.Removing element after given element\n10.Display elements in list\n11.Exit\n\n");
	do
	{
		printf("enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				head=head_insertion(head);
				break;
			}
			case 2:
			{
				head=tail_insertion(head);
				break;
			}
			case 3:
			{
				head=middle_insertion(head);
				break;
			}
			case 4:
			{
				head=pos_insertion(head);
				break;
			}
			case 5:
			{
				searching(head);
				break;
			}
			case 6:
			{
				head=rem_element(head);
				break;
			}
			case 7:
			{
				head=rem_position(head);
				break;
			}
			case 8:
			{
				head=rem_before(head);
				break;
			}
			case 9:
			{
				rem_after(head);
				break;
			}
			case 10:
			{
				display(head);
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
