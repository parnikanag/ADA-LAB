#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) 
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l;
	
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		} 
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) 
{
	if (l < r) 
	{

		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
int main() 
{
	FILE *fp;
	fp = fopen("numbers.txt", "w");
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	srand(time(NULL));
	for (int i = 0; i < n; i++) 
	{
		int num = rand() % 10000;
		fprintf(fp, "%d ", num);
	}
	fclose(fp);
	int arr[n];
	fp = fopen("numbers.txt", "r");
	for (int i = 0; i < n; i++) 
	{
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	mergeSort(arr, 0, n - 1);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
	return 0;
}
