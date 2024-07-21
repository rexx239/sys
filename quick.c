#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int a[], int low, int high)
{
    int i, j, temp, pivot;
    pivot = a[low];
    i = low;
    j = high + 1;
    while (i <= j)
    {
        do
            i++;
        while (pivot >= a[i]);
        do
            j--;
        while (pivot < a[j]);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void qs(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        qs(a, low, mid - 1);
        qs(a, mid + 1, high);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    // Generate random numbers for the array
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000; 

    }
    // Measure the time taken to sort the array
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    qs(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) /CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken for sorting: %f seconds\n",cpu_time_used);
    return 0;
}