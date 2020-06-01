#include<stdio.h>
#include<stdlib.h>
#define max 1000
int count;
int partition (int a[max],int low,int high)
{
	int i,j,pivot,temp;

	i=low+1;
	j=high;
	pivot=a[low];
	while(1)
	{
		while (pivot>=a[i] && i<high)
		{
			i++;
			count++;
		}
		while (pivot<a[j])
		{ 
			j--;
			count++;
		}
		count++;
		if (i<j)  //swap i and j
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else   //swap pivot and j
		{
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;
			return j;
		}
	}
}

void quicksort(int a[],int low, int high)
{
	int j;
	if (low<high)
	{
		j=partition(a,low,high);   //return the position of pivot element after placing it in its correct position.
		quicksort(a,low,j-1);     //recursively sorts the left part
		quicksort(a,j+1,high);    //recursively sorts the right part
	}
}

int main()
{
	int n,i,j,a[max],b[max],c[max],n1,n2,n3;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for (i=0;i<n;i++)
	{
		printf("Element:");
		scanf("%d",&a[i]);	
	}
	count=0;
	quicksort(a,0,n-1);
	printf("Sorted array:\n");
	for (i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\nCount: %d",count);
	
	printf("\n\n\tAscending\tDEscending\tRandom\n");
	for (i=16;i<600;i*=2)
	{
		for (j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand();
		
		}
		count=0;
		quicksort(a,0,i-1);
		n1=count;
		count=0;
		quicksort(b,0,i-1);
		n2=count;
		count=0;
		quicksort(c,0,i-1);
		n3=count;
		printf("%d\t%d\t\t%d\t\t%d\n",i,n1,n2,n3);
	}
	return 0;	
}
