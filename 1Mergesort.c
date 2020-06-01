#include<stdio.h>
int b[600],count=0;
void merge(int a[],int low,int mid,int high){
	int i=low,j=mid+1,k=low;

	while(i<=mid && j<=high){
		count++;
		if(a[i]>a[j])
			b[k++]=a[j++];
		else
			b[k++]=a[i++];
	}

	for(;i<=mid;i++){      //if remaining elements in left array directly copy to b because already sorted
		count++;   
		b[k++]=a[i];
	}

	for(;j<=high;j++){    //if remaining elements in right array directly copy to b because already sorted
		count++;
		b[k++]=a[j];
	}

	for(i=0;i<=high;i++)  //copy all sorted elements to the original array 
		a[i]=b[i];
}

void mergeSort(int a[],int low,int high){
	int mid;
	if(low<high){
		count++;
		mid=(low+high)/2;
		mergeSort(a,low,mid);    //recursively sort the left half
		mergeSort(a,mid+1,high); //recursively sort the right half
		merge(a,low,mid,high);   //merge the two sorted halves
	}
}

void main(){
	int a[600],b[600],c[600],i,j,n;

	printf("\nEnter the size of array :");
	scanf("%d",&n);

	printf("\nEnter the array elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	mergeSort(a,0,n-1);

	printf("\nThe Sorted array is :");

	for(i=0;i<n;i++)
		printf("\t%d",a[i]);

	printf("\nThe count is : %d",count);

	printf("\nTesting algorithm for Ascending, Descending and Random Arrays\n");
	printf("Size \tAscen \tDesc \tRandom\n");

	for(i=16;i<=600;i=i*2){
		for(j=1;j<=i;j++){
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}

		count=0;
		mergeSort(a,1,i);
		printf("\n%d\t%d",i,count);

		count=0;
                mergeSort(b,1,i);
                printf("\t%d",count);

		count=0;
                mergeSort(c,1,i);
                printf("\t%d",count);
	}
	
}

