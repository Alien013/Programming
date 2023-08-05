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

int main()
{
    int n, k;
    cin >> n >> k;

    int dnm[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dnm[i];
    }

    int ans = 0;

    quick_sort(dnm, 0, n - 1);

    for (int i = 0; i < n / 2; i++)
    {
        swap(dnm[i], dnm[n - i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (dnm[i] <= k)
        {
            ans += k / dnm[i];
            k = k % dnm[i];
            // cout << dnm[i] << " " << ans <<"\n";
        }
    }

    k ? cout << "-1" : cout << ans;
    return 0;
}
