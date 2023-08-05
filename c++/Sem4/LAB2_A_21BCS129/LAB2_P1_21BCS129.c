#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Recursive(int low, int high, int arr[], int key)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] > key)
    {
        return Recursive(low, mid - 1, arr, key);
    }
    else if (arr[mid] < key)
        return Recursive(mid + 1, high, arr, key);

    else
        return mid;
}

int iterative(int low, int high, int arr[], int key)
{
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > key)
            high = mid - 1;
        else if (arr[mid] < key)
            low = mid - 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int n, k, count = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        ++count;
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
        ++count;
    }
    printf("\n");

    scanf("%d", &k);
    printf(Recursive(0, n - 1, arr, k) + "  " + iterative(0, n - 1, arr, k));
    printf("Element found");
    return 0;
}