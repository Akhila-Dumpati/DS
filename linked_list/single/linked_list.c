#include<stdio.h>
#include<stdlib.h>

struct node{
	int e;
	struct node *next;
};

struct node* head_insertion(struct node *head)
{
	int ele;
	printf("enter element: ");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->e=ele;
		head->next=NULL;
	}
	else
	{
		struct node *nn;
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		nn->next=head;
		head=nn;
	}
	return head;
}

struct node* tail_insertion(struct node *head)
{
	int ele;
	printf("enter element: ");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->e=ele;
		head->next=NULL;
	}
	else
	{
		struct node *temp=head;;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		struct node *nn;
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		nn->next=NULL;
		temp->next=nn;
	}
	return head;
}
struct node* middle_insertion(struct node *head)
{
	int ele,c=0,pos;
	struct node *temp=head;
	printf("enter element: ");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->e=ele;
		head->next=NULL;
	}
	else if(head->next==NULL)
	{
		struct node *nn;
		nn=(struct node *)malloc(sizeof(struct node));
		nn->e=ele;
		nn->next=NULL;
		head->next=nn;
	}
	else
	{
		while(temp!=NULL)
		{
			temp=temp->next;
			c++;
		}
		pos=(c/2)-1;
		c=0;
		temp=head;
		while(c!=pos)
		{
			temp=temp->next;
			c++;
		}
		struct node *nn;
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		nn->next=temp->next;
		temp->next=nn;
		return head;
	}
}

struct node* pos_insertion(struct node *head)
{
	struct node *nn,*temp;
	temp=head;
	int pos,c=0,ele;
	printf("enter position(from 1): ");
	scanf("%d",&pos);
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	if(pos>c && head!=NULL)
	{
		printf("insertion at given position is not possible\n");
	}
	else
	{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("enter element: ");
		scanf("%d",&ele);		
		if(pos==1)
		{
			nn->e=ele;
			nn->next=head;
			head=nn;
		}
		else
		{
			c=1;
			temp=head;
			while(c<pos-1)
			{
				temp=temp->next;
				c++;
			}
			nn->e=ele;
			nn->next=temp->next;
			temp->next=nn;
		}
	}
	return head;
}

void searching(struct node *head)
{
	struct node *temp=head;
	int ele,f=0;
	if(head==NULL)
	{
		printf("no elements in linked list\n");
	}
	else
	{
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
			{
				temp=temp->next;
			}
		}
		if(f==1)
			printf("%d is found\n",ele);
		else
			printf("%d is not found\n",ele);		
	}
}

struct node* rem_element(struct node *head)
{
	struct node *temp=head;
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
			if(head->e==ele)
			{
				head=head->next;
			}
			else
			{
				struct node *temp1=head;
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
	return head;
}

struct node* rem_position(struct node *head)
{
	struct node *temp=head->next, *temp1=head;
	int pos,c=1;
	printf("enter position: ");
	scanf("%d",&pos);
	if(head==NULL || pos<=0)
	{
		printf("removing not possible\n");
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
		}
	}	
	return head;
}

struct node* rem_before(struct node *head)
{
	struct node *temp=head;
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
			if(head->e==ele)
				printf("removing is not possible\n");
			else if(head->next->e==ele)
				head=head->next;
			else
			{
				struct node *temp1=head;
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
	return head;
}
void rem_after(struct node *head)
{
	struct node *temp=head;
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
	
void display(struct node *head)
{
	struct node *temp=head;
	if(head!=NULL)
	{
		printf("ELEMENTS IN LINKEDLIST:");
		while(temp!=NULL)
		{
			printf("%d ",temp->e);
			temp=temp->next;
		}
		printf("\n");
	}
	else
	{
		printf("list is empty\n");
	}
}

int main()
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
