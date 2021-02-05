// tree and its operations

#include<stdio.h>
#include<stdlib.h>

struct tree_node
{
	struct tree_node *left;
	int e;
	struct tree_node *right;
};

struct queue
{
	struct tree_node *a[500];
	int front;
	int rear;
	int max;
};

struct queue* enqueue(struct tree_node *temp,struct queue *q)
{
	q->front++;
	q->a[q->front]=temp;
	return q;
}

struct tree_node* dequeue(struct queue *q)
{
	q->rear++;	
	return q->a[q->rear];
}

int isempty(struct queue *q)
{
	if(q->front == q->rear)
		return 1;
	else
		return 0;
}
struct tree_node* find(struct tree_node *root,int ele,struct queue *q)
{
	struct tree_node *temp=root,temp1;
	int f=0;
	enqueue(temp,q);
	while(!isempty(q))
	{
		temp=dequeue(q);
		if(temp->e==ele)
		{
			f=1;
			printf("%d is ele\n",temp->e);
			return temp;
		}
		else
		{
			if(temp->left!=NULL)
			{
				enqueue(temp->left,q);
			}
			if(temp->right!=NULL)
			{
				enqueue(temp->right,q);
			}
		}
		if(f==0)
		{
			return NULL;
		}
	}
	while(!isempty(q))
		temp=dequeue(q);
}

struct	tree_node* find_parent(struct tree_node *root,struct tree_node *temp,struct queue *q)
{
	struct tree_node *temp1,*temp2;
	int f=0;
	enqueue(root,q);
	while(!isempty(q))
	{
		temp1=dequeue(q);
		if(temp1->left==temp)
		{
			printf("%d is parent of last ele\n",temp1->e);
			return temp1;
		}
		else
		{
			if(temp1->left!=NULL)
			{
				enqueue(temp1->left,q);
			}
		}
		if(temp1->right==temp)
		{
			printf("%d is parent of last ele\n",temp1->e);
			return temp1;
		}
		else
		{
			if(temp1->right!=NULL)
			{
				enqueue(temp1->left,q);
			}
		}
	}
	while(!isempty(q))
		temp=dequeue(q);
}	

struct tree_node* find_last(struct tree_node* root,struct queue *q)
{
	struct tree_node *temp=root,*temp1;
	enqueue(temp,q);
	while(!isempty(q))
	{
		temp=dequeue(q);
		if(temp->left!=NULL)
		{
			enqueue(temp->left,q);
		}
		if(temp->right!=NULL)
		{
			enqueue(temp->left,q);
		}
	}
	printf("%d is last ele\n",temp->e);
	return temp;
	while(!isempty(q))
		temp=dequeue(q);
}

struct tree_node* insert(struct tree_node *root,struct queue *q)
{
	struct tree_node *nn,*temp=root;
	int ele;
	printf("enter element to insert: ");
	scanf("%d",&ele);
	if(root==NULL)
	{
		root=(struct tree_node*)malloc(sizeof(struct tree_node));
		root->e=ele;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		enqueue(root,q);
		while(1)
		{
			temp=dequeue(q);
			if(temp->left!=NULL)
			{
				enqueue(temp->left,q);
			}
			else
			{
				break;
			}
			if(temp->right!=NULL)
			{
				enqueue(temp->right,q);
			}
			else
			{
				break;
			}
		}
	nn=(struct tree_node *)malloc(sizeof(struct tree_node));
	nn->e=ele;
	nn->left=NULL;
	nn->right=NULL;
	if(temp->left==NULL)
		temp->left=nn;
	else
		temp->right=nn;
	}
	while(!isempty(q))
		temp=dequeue(q);
	return root;
}

struct tree_node* delete(struct tree_node *root,struct queue *q)
{
	if(root==NULL)
	{
		printf("Deletion is not possible\n");
	}
	else
	{
		
		int ele;
		printf("enter element to delete: ");
		scanf("%d",&ele);
		struct tree_node *temp,*temp1,*temp2;
		temp=find(root,ele,q);
		if(temp!=NULL)
		{
			temp1=find_last(root,q);
			temp2=find_parent(root,temp1,q);
			temp->e=temp1->e;
			if(temp2->left==temp1)
			{
				temp2->left=NULL;
			}
			else
			{
				temp2->right=NULL;
			}
		}
	}
	return root;
}

void search(struct tree_node *root,struct queue *q)
{
	struct tree_node *temp=root;
	int ele,f=0;
	printf("enter element: ");
	scanf("%d",&ele);
	enqueue(root,q);
	while(!isempty(q))
	{
		temp=dequeue(q);
		if(temp->e==ele)
		{
			f=1;
			break;
		}
		else
		{
			if(temp->left!=NULL)
				enqueue(temp->left,q);
			if(temp->right!=NULL)
				enqueue(temp->right,q);
		}
	}
	if(f==1)
		printf("%d is found\n",ele);
	else
		printf("%d is not found\n",ele);
	while(!isempty(q))
		temp=dequeue(q);
}

void length(struct tree_node *root,struct queue *q)
{
	struct tree_node *temp=root;
	int len=0;
	enqueue(root,q);
	while(!isempty(q))
	{
		temp=dequeue(q);
		len++;
		if(temp->left!=NULL)
			enqueue(temp->left,q);
		if(temp->right!=NULL)
			enqueue(temp->right,q);
	}
	printf("length of tree is:%d \n",len);
	while(!isempty(q))
		temp=dequeue(q);
}

void display(struct tree_node *root,struct queue *q)
{
	struct tree_node *temp=root;
	enqueue(root,q);
	while(!isempty(q))
	{
		temp=dequeue(q);
		printf("%d ",temp->e);
		if(temp->left!=NULL)
			enqueue(temp->left,q);
		if(temp->right!=NULL)
			enqueue(temp->right,q);
	}
	printf("\n");
	while(!isempty(q))
		temp=dequeue(q);
}

void main()
{
	struct tree_node *root=NULL;
	struct queue *q;
	q->front=-1;
	q->rear=-1;
	int op;
	printf("1.Insert an element into tree\n2.Remove an element from tree\n3.search an element\n4.length of tree\n5.Display an element from tree\n");
	do
	{
		printf("enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				root=insert(root,q);
				break;
			}
			case 2:
			{
				root=delete(root,q);
				break;
			}
			case 3:
			{
				search(root,q);
				break;
			}
			case 4:
			{
				length(root,q);
				break;
			}
			case 5:
			{	
				display(root,q);
				break;
			}
			case 6:
			{
				printf("THANK YOU\n");
				break;
			}
			default:
			{
				printf("invalid option\n");
				break;
			}
		}
	}while(op!=6);
}
