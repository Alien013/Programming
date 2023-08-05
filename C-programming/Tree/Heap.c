#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void swap(int *a, int *b)
{
    int k = *a;
    *a = *b;
    *b = k;
}

void max_heapify(int arr[], int n, int i)
{

    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[mx])
    {
        mx = l;
    }
    if (r < n && arr[r] > arr[mx])
    {
        mx = r;
    }

    if (mx != i)
    {
        swap(&arr[i], &arr[mx]);
        max_heapify(arr, n, mx);
    }
}

void build_max_heap(int arr[], int n)
{

    int ind = n / 2 + 1;

    for (int i = ind; i >= 0; i--)
    {
        max_heapify(arr, n, i);
    }
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

int heap_max(int arr[], int n)
{
    int max = arr[0];
    return max;
}

int heap_extract_max(int arr[], int *n)
{

    if (*n >= 1)
    {
        int max = arr[0];
        swap(&arr[0], &arr[*n - 1]);
        *n = *n - 1;
        max_heapify(arr, *n, 0);
        return max;
    }
    else
    {
        printf("Heap underflow!");
        return -1;
    }
}

void heap_increase_key(int arr[], int n, int i, int k)
{
    if (k < arr[i])
    {
        printf("Please enter a larger value than the current key.");
    }
    else
    {
        arr[i] = k;
        while (i > 0 && arr[((i + 1) / 2) - 1] < arr[i])
        {
            swap(&arr[((i + 1) / 2) - 1], &arr[i]);
            i = ((i + 1) / 2) - 1;
        }
    }
}

void max_heap_insert(int arr[], int *n, int k)
{

    if (*n < MAX)
    {
        *n = *n + 1;
        arr[*n - 1] = INT_MIN;
        heap_increase_key(arr, *n, *n - 1, k);
    }
    else
    {
        printf("Heap overflow!\n");
    }
}

void max_heap_delete(int arr[], int *n, int i)
{
    if (*n > 0)
    {
        int del = arr[i];
        swap(&arr[i], &arr[*n - 1]);
        *n = *n - 1;
        max_heapify(arr, *n, i);
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
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }

    printf("\nArray :\n");
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

    build_max_heap(arr2, n);

    printf("\nMax Heap :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // printf("%d\n", heap_max(arr2,n));
    // printf("%d\n", heap_extract_max(arr2,&n));

    // printf("\nMax Heap :\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr2[i]);
    // }
    // printf("\n");

    // heap_increase_key(arr2, n, 4, 20);
    // printf("\nMax Heap :\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr2[i]);
    // }
    // printf("\n");

    max_heap_insert(arr2, &n, 20);
    printf("\nMax Heap after insertion :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    max_heap_delete(arr2, &n, 0);
    printf("\nMax Heap after deletion :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}

// #include <stdio.h>
// #include <limits.h>

// /*Declaring heap globally so that we do not need to pass it as an argument every time*/
// /* Heap implemented  here is Min Heap */

// int heap[1000000], heapSize;
// /*Initialize Heap*/
// void Init()
// {
//     heapSize = 0;
//     heap[0] = -INT_MAX;
// }

// /*Insert an element into the heap */
// void Insert(int element)
// {
//     heapSize++;
//     heap[heapSize] = element; /*Insert in the last place*/
//     /*Adjust its position*/
//     int now = heapSize;
//     while (heap[now / 2] > element)
//     {
//         heap[now] = heap[now / 2];
//         now /= 2;
//     }
//     heap[now] = element;
// }

// int DeleteMin()
// {
//     /* heap[1] is the minimum element. So we remove heap[1]. Size of the heap is decreased.
//      Now heap[1] has to be filled. We put the last element in its place and see if it fits.
//      If it does not fit, take minimum element among both its children and replaces parent with it.
//      Again See if the last element fits in that place.*/
//     int minElement, lastElement, child, now;
//     minElement = heap[1];
//     lastElement = heap[heapSize--];
//     /* now refers to the index at which we are now */
//     for (now = 1; now * 2 <= heapSize; now = child)
//     {
//         /* child is the index of the element which is minimum among both the children */
//         /* Indexes of children are i*2 and i*2 + 1*/
//         child = now * 2;
//         /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only one
//          child */
//         if (child != heapSize && heap[child + 1] < heap[child])
//         {
//             child++;
//         }
//         /* To check if the last element fits ot not it suffices to check if the last element
//          is less than the minimum element among both the children*/
//         if (lastElement > heap[child])
//         {
//             heap[now] = heap[child];
//         }
//         else /* It fits there */
//         {
//             break;
//         }
//     }
//     heap[now] = lastElement;
//     return minElement;
// }

// int main()
// {
//     int number_of_elements;
//     printf("Program to demonstrate Heap:\nEnter the number of elements: ");
//     scanf("%d", &number_of_elements);
//     int iter, element;
//     Init();
//     printf("Enter the elements: ");
//     for (iter = 0; iter < number_of_elements; iter++)
//     {
//         scanf("%d", &element);
//         Insert(element);
//     }
//     for (iter = 0; iter < number_of_elements; iter++)
//     {
//         printf("%d ", DeleteMin());
//     }
//     printf("\n");
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 20
// void maxheapify(int *, int, int);
// int *buildmaxheap(int *, int);
// void main()
// {
//     int i, t, n;
//     int *a = calloc(MAX, sizeof(int));
//     int *m = calloc(MAX, sizeof(int));
//     printf("Enter no of elements in the array\n");
//     scanf("%d", &n);
//     printf("Enter the array\n");
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     m = buildmaxheap(a, n);
//     printf("The heap is\n");
//     for (t = 0; t < n; t++)
//     {
//         printf("%d\n", m[t]);
//     }
// }
// int *buildmaxheap(int a[], int n)
// {
//     int heapsize = n;
//     int j;
//     for (j = n / 2; j >= 0; j--)
//     {
//         maxheapify(a, j, heapsize);
//     }
//     return a;
// }
// void maxheapify(int a[], int i, int heapsize)
// {
//     int temp, largest, left, right, k;
//     left = (2 * i + 1);
//     right = ((2 * i) + 2);
//     if (left >= heapsize)
//         return;
//     else
//     {
//         if (left < (heapsize) && a[left] > a[i])
//             largest = left;
//         else
//             largest = i;
//         if (right < (heapsize) && a[right] > a[largest])
//             largest = right;
//         if (largest != i)
//         {
//             temp = a[i];
//             a[i] = a[largest];
//             a[largest] = temp;
//             maxheapify(a, largest, heapsize);
//         }
//     }
// }
