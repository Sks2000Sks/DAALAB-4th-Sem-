#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int len,a[1000],count=0;

void heapify(int i)
{
	
	int flag=0,k=i,v=a[i],j;
	while (!flag && 2*k<=len)     
	{
		count++;
		j=2*k;                       //left child node
		if (j<len)                   //should be withinh the array limit
		{
			if (a[j]<a[j+1])     //if right child is greater then move to right child
				j=j+1;
		}
		if (v>=a[j])                //root is greater than both the children
			flag=1;
		else
		{
			a[k]=a[j];         //put the grater child into the root node
			k=j;
		}
	}
	a[k]=v;        //root value to child node(which was put to root)
                       //if flag =true then same element will be pu to same element
	              //root value should be compared with all levels only then it should be placed

}

void heap()
{
	int i,t;
	count++;
	for (i=len/2.0;i>0;i--)    //len/2 mins first internal node starts from here
	{
		heapify(i);
	}
	for (i=len;i>=2;i--)
	{
		count++;
		t=a[len];
		a[len]=a[1];
		a[1]=t;
		len--;
		heapify(1);
	}
}

int main()
{
	int i,j,n,c1,c2,c3;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	len=n;
	printf("\nEnter %d elements:\n",n);
	for (i=1;i<=len;i++)
		scanf("%d",&a[i]);
	heap();
	printf("\nSorted array is \n\n");
	for (i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n\n no of counts:%d\n",count);
	printf("\n\nsize\tasc\tdesc\trandom\n");
	for (i=16;i<520;i*=2)
	{
		count=0;
		len=i;
		for (j=1;j<=i;j++)
			a[j]=j;
		heap();
		c1=count;
		count=0;
		len=i;
		for (j=1;j<=i;j++)
			a[j]=i-j;
		heap();
		c2=count;
		count=0;len=i;
		for (j=1;j<=i;j++)
			a[j]=rand()%i;
		heap();
		c3=count;
		printf("\n%d\t%d\t%d\t%d",i,c1,c2,c3);
	}
	return 0;
}
