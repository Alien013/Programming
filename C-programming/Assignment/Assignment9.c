#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void swap(int *a, int *b)
{
    int k = *a;
    *a = *b;
    *b = k;
}
void min_heapify(int arr[], int n, int i)
{

    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[mx])
    {
        mx = l;
    }
    if (r < n && arr[r] < arr[mx])
    {
        mx = r;
    }

    if (mx != i)
    {
        swap(&arr[i], &arr[mx]);
        min_heapify(arr, n, mx);
    }
}

void build_min_heap(int arr[], int n)
{

    int ind = n / 2 + 1;

    for (int i = ind; i >= 0; i--)
    {
        min_heapify(arr, n, i);
    }
}

void heap_increase_key(int arr[], int n, int i, int k)
{
    if (k > arr[i])
    {
        printf("Please enter a larger value than the current key.");
    }
    else
    {
        arr[i] = k;
        while (i > 0 && arr[((i + 1) / 2) - 1] > arr[i])
        {
            swap(&arr[((i + 1) / 2) - 1], &arr[i]);
            i = ((i + 1) / 2) - 1;
        }
    }
}
void min_heap_insert(int arr[], int *n, int k)
{

    if (*n < MAX)
    {
        *n = *n + 1;
        arr[*n - 1] = k;
        heap_increase_key(arr, *n, *n - 1, k);
    }
    else
    {
        printf("Heap overflow!\n");
    }
}
void min_heap_delete(int arr[], int *n, int i)
{
    if (*n > 0)
    {
        int del = arr[i];
        swap(&arr[i], &arr[*n - 1]);
        *n = *n - 1;
        min_heapify(arr, *n, i);
    }
    else
    {
        printf("Heap underflow!\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr1[MAX], arr2[MAX];
    printf("Enter the Execution time for the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }
    printf("\nExecution time using min heap:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    build_min_heap(arr1, n);

    printf("\nMin Heap :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int N;
    printf("\n Enter the number to insert in heap\n");
    scanf("%d", &N);
    min_heap_insert(arr1, &n, N);
    printf("\nMin Heap after insertion :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int m;
    printf("Enter the position of element to delete\n");
    scanf("%d", &m);
    min_heap_delete(arr1, &n, m);
    printf("\nMax Heap after deletion :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}

//Anova?        