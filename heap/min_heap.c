#include<stdio.h>
	
void heapify(int a[],int n,int i)
{
	int j,l,r,temp,min=-1;
	l=2*i+1;
	r=2*i+2;
	if(r<n)
	{
		if(a[r]<a[l])
			min=r;
		else
			min=l;
	}
	else if(l<n)
	{
		min=l;
	}
	if(a[i]>a[min] && min!=-1)
	{
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
		heapify(a,n,min);
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

