#include<stdio.h>

void main()
{
	int n,i,j,temp;
	printf("enter no. of elements:");
	scanf("%d",&n);
	int a[n];
	printf("enter %d elements: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
