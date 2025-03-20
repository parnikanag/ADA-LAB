#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    FILE *fp;
    fp = fopen("numbers.txt", "w");
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    srand(time(NULL));
    
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int num = rand() % 10000;
        fprintf(fp, "%d ", num);
    }
    fclose(fp);

    int *arr = (int *)malloc(n * sizeof(int));  // Dynamic memory allocation

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        free(arr);  // Free the allocated memory before exiting
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);

    free(arr);  // Free the allocated memory after use

    return 0;
}

