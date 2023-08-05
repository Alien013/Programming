#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;

    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quick_sort(int arr[], int start, int end)
{

    if (start >= end)

        return;

    int p = partition(arr, start, end);

    quick_sort(arr, start, p - 1);

    quick_sort(arr, p + 1, end);
}

int hIndex(int citations[], int n)
{

    quick_sort(citations, 0, n - 1);
    int hi = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (n - i <= citations[i])
        {
            hi++;
        }
    }

    return hi;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        // arr[i] = rand() % 10;
        cin >> arr[i];
    }

    cout << "Random Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << hIndex(arr, n) << endl;

    return 0;
}