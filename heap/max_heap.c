#include<stdio.h>
	
void heapify(int a[],int n,int i)
{
	int l,r,temp,max=-1;
	l=2*i+1;
	r=2*i+2;
	if(r<n)
	{
		if(a[r]>a[l])
			max=r;
		else
			max=l;
	}
	else if(l<n)
	{
		max=l;
	}
	if(a[i]<a[max] && max!=-1)
	{
		temp=a[i];
		a[i]=a[max];
		a[max]=temp;
		heapify(a,n,max);
	}
}

void main()
{
	int i,n,j;
	printf("enter size of heap: ");
	scanf("%d",&n);
	int a[n];
	printf("%d elements: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i<n/2;i>=0;i--)
		heapify(a,n,i);
	for(j=0;j<n;j++)
		printf("%d ",a[j]);
}

