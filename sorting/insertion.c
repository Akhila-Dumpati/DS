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
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
