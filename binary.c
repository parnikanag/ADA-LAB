#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int bin_search(int arr1[15000],int n,int key)
{
int i, temp;
for(i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr1[j]>arr1[j+1])
			{
				temp=arr1[j];
				arr1[j]=arr1[j+1];
				arr1[j+1]=temp;
			}
		}
	}
int start=arr1[0];
int end=arr1[n-1];
for(i=0;i<n;i++)
{
	int mid=arr1[n/2];
	if(arr1[mid]==key)
	{
		return i;
	}
	else if(mid<key)
	{
		end=mid;
	}
	else
	{
	start=mid;
}
}
return -1;
}
void main()
{
	clock_t start,end;
	int arr[15000];
	int key;
	double elapsed_time;
	int n;
	printf("enter the key value:\n");
	scanf("%d",&key);
	printf("enter the total numberof n\n");
	scanf("%d",&n);
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%10000;
	}
	int index;
	start=clock();
	index=bin_search(arr,n,key);
	end=clock();
	elapsed_time=((double)end-start)/CLOCKS_PER_SEC;
	if(index==-1)
	{
		printf("element not found!");
	}
	else
	{
		printf("element is found at index %d",index);
	}
	printf("the total time taken to sort the elements is %f",elapsed_time);
	printf("sorted elements are:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
