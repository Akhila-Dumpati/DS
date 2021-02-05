#include<stdio.h>

int a[20][20],visit[20],n;

void dfs(int k)
{
	if (visit[k]==0)
	{
		visit[k]=1;
		printf("%d ",k);
		for(int j=0;j<n;j++)
		{
			if(a[k][j]==1 && visit[j]==0)
				dfs(j);
		}
	}
}

void main()
{
	int i,j;
	printf("enter no. of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter 1 if edge is exist else 0 for node-%d to %d:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	dfs(0);
	for(i=0;i<n;i++)
	{
		dfs(i);
	}
}


