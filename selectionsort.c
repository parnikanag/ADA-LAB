#include<stdio.h>
void selectionsort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
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
    selectionsort(arr,n);
    printf("Sorted Array:\n");
    printarray(arr,n);
    return 0;

}
