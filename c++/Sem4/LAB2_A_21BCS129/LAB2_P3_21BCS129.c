#include <stdio.h>
int count = 0;
int partition(int Arr[], int start, int end)
{
    int pivot = Arr[end];
    int i = (start - 1);
    count++;
    for (int j = start; j <= end - 1; j++)
    {

        if (Arr[j] < pivot)
        {
            i++;
            int t = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = t;
            count++;
        }
        count++;
    }
    int t = Arr[i + 1];
    Arr[i + 1] = Arr[end];
    Arr[end] = t;
    count++;
    return (i + 1);
}

void QuickSort(int Arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(Arr, start, end);
        QuickSort(Arr, start, p - 1);
        QuickSort(Arr, p + 1, end);
        count++;
    }
    count++;
}

void printArr(int Arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", Arr[i]);
    count++;
}
int main()
{
    int n;
    scanf("%d", &n);
    int Arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
        count++;
    }
    printf("Before sorting array elements are - \n");
    printArr(Arr, n);

    QuickSort(Arr, 0, n - 1);
    count++;
    printf("\nAfter sorting array elements are - \n");
    printArr(Arr, n);
    count++;
    printf("\nNo. of steps is %d", count);

    return 0;
} 