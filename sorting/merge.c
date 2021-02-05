#include<stdio.h>

void merge(int a[],int p,int q,int r)
{
	int i=p,j=q+1,k=r,s=0;
	int b[k+1];
	while(i<=q&&j<=r)
	{
		if(a[i]<a[j])
		{
			b[s++]=a[i++];
		}
		else
		{
			b[s++]=a[j++];
		}
	}
	while(i<=q)
	{
		b[s++]=a[i++];
	}
	while(j<=r)
	{
		b[s++]=a[j++];
	}
	for(i=0;i<k;i++)
		a[p+i]=b[i];
}

void merge_sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

void main()
{
	int n,i;
	printf("enter no. of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
