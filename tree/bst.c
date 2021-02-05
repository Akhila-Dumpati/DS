//binary search tree and its operations
#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	struct tnode *left;
	int e;
	struct tnode *right;
};

struct tnode* insert(struct tnode *root)
{
	struct tnode *nn,*parent=NULL,*temp=root;
	int ele;
	nn=(struct tnode*)malloc(sizeof(struct tnode));
	printf("enter element to insert: ");
	scanf("%d",&ele);
	nn->e=ele;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL)
	{
		root=nn;
	}
	else
	{
		while(temp!=NULL)
		{
			parent=temp;
			if(temp->e < nn->e)
				temp=temp->right;
			else
				temp=temp->left;
		}
		if(parent->e < nn->e)
			parent->right=nn;
		else
			parent->left=nn;
	}
	return root;
}

struct tnode *minValueNode(struct tnode *temp) 
{
  struct tnode*temp1=temp;
  while(temp1->left!= NULL)
    temp1=temp1->left;
  return temp1;
}

struct tnode* delete(struct tnode *root, int key)
{
	if (root == NULL) 
		return root;
	if (key < root->e)
    root->left = delete(root->left, key);
	else if (key > root->e)
    root->right = delete(root->right, key);
	else 
	{
		if (root->left == NULL)
		{
		   struct tnode *temp = root->right;
		   free(root);
		   return temp;
		}
		else if (root->right == NULL) 
		{
		   struct tnode *temp = root->left;
		   free(root);
		   return temp;
		 }
		 struct tnode *temp = minValueNode(root->right);
		 root->e = temp->e;
		 root->right = delete(root->right, temp->e);
	 }
  return root;	
}

void search(struct tnode *root)
{
	struct tnode *temp=root;
	int ele,f=0;
	printf("Enter element to search: ");
	scanf("%d",&ele);
	while(temp!=NULL)
	{
		if(temp->e==ele)
		{
			f=1;
			break;
		}
		else if(temp->e > ele)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(f==1)
		printf("found");
	else
		printf("not found");		
}

void preorder(struct tnode *root)
{
	struct tnode *temp=root;
	if(temp!=NULL)
	{
		printf("%d ",temp->e);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(struct tnode *root)
{
	struct tnode*temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->e);
		inorder(temp->right);
	}
}

void postorder(struct tnode *root)
{
	struct tnode*temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->e);
	}
}

void main()
{
	struct tnode *root=NULL;
	int op,f;
	printf("1.Insertion\n2.Deletion\n3.Searching\n4.pre-order traversal\n5.in-order traversal\n6.post-order traversal\n7.Exit");
	do{
		printf("\nenter choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				root=insert(root);
				break;
			}
			case 2:
			{
				int key;
				printf("enter element to delete: ");
				scanf("%d",&key);
				root=delete(root,key);
				break;
			}
			case 3:
			{
				search(root);
				break;
			}
			case 4:
			{
				preorder(root);
				break;
			}
			case 5:
			{
				inorder(root);
				break;
			}
			case 6:
			{
				postorder(root);
				break;
			}
			case 7:
			{
				printf("Thank You\n");
				break;
			}
			default:
			{
				printf("Invalid option");
			}
		}
	}while(op!=7);
}
