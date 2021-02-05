#include<stdio.h>

void quick_sort(int a[],int st,int end)
{
	int pivot,i,j,temp;
	if(end-st>1)
	{
		i=st+1;
		j=end;
		pivot=a[st];
		while(i<j)
		{
			while(a[i]<pivot && i<=end)
			{
				i++;
			}
			while(a[j]>pivot && j>=0)
			{
				j--;
			}
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}	
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quick_sort(a,st,j-1);
		quick_sort(a,j+1,end);
	}
	else
	{
		int i=st,j=end;
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}	
}

void main()
{
	int n,i;
	printf("enter no. of elements\n");
	scanf("%d",&n);
	printf("enter %d elements\n",n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d",a[i]);
}

