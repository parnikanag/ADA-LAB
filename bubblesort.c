#include<stdio.h>
void bubblesort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j =0 ; j < n-1-i; j++)
        {
            if (a[j] >a[j+1])
            {
                temp = a[j];
        		a[j] = a[j+1];
        		a[j+1] = temp;
            }
        }
        
    }
}
void  printarray(int arr[],int n)
{
	for (int i=0;i<n;i++)
    
    	printf("%d\t",arr[i]);
    printf("\n");
    
}

int main()
{
	int n,arr[20];
	printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
    }
    printf("\nOriginal Array:\n");
    printarray(arr,n);
    bubblesort(arr,n);
    printf("Sorted Array:\n");
    printarray(arr,n);
    return 0;

}
