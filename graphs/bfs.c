#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int a[20];
	int f;
	int r;
};

struct queue* enqueue(struct queue *q,int ele)
{
	q->r++;
	q->a[q->r]=ele;
	return q;
}

int dequeue(struct queue *q)
{
		q->f++;
		return q->a[q->f];
}
int isempty(struct queue *q)
{
	if(q->f == q->r)
		return 1;
	else
		return 0;
}

void main()
{
	struct queue *q;
	q=(struct queue*)malloc(sizeof(struct queue));
	q->f=-1;
	q->r=-1;
	int i,j,k,n;
	printf("enter no. of nodes:");
	scanf("%d",&n);
	int m[n][n],visit[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter 1 if edge is exist else 0 for node-%d to %d:",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		visit[i]=0;
	}
	q=enqueue(q,0);
	while(!isempty(q))
	{
		k=dequeue(q);
		if(visit[k]==0)
		{
			visit[k]=1;
			printf("%d ",k);
			for(j=0;j<n;j++)
			{
				if(m[k][j]==1 && visit[j]==0)
				{
					q=enqueue(q,j);
				}
			}
		}
	}
	/*for(i=0;i<n;i++)
		printf("%d ",b[i]);*/
}
	
	
