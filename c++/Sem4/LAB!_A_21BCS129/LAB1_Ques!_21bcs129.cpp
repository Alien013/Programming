// Question 1
// #include <bits/stdc++.h>
// using namespace std;
int step=0;
// int partition(int arr[], int start, int end)
// {

//     int pivot = arr[start];

//     int count = 0;
//     for (int i = start + 1; i <= end; i++)
//     {
//         if (arr[i] <= pivot)
//             count++;
//     }

//     int pivotIndex = start + count;
//     swap(arr[pivotIndex], arr[start]);

//     int i = start, j = end;

//     while (i < pivotIndex && j > pivotIndex)
//     {

//         while (arr[i] <= pivot)
//         {
//             i++;
//         }

//         while (arr[j] > pivot)
//         {
//             j--;
//         }

//         if (i < pivotIndex && j > pivotIndex)
//         {
//             swap(arr[i++], arr[j--]);
//         }
//     }

//     return pivotIndex;
// }

// void quickSort(int arr[], int start, int end)
// {

//     if (start >= end)
//         return;

//     int p = partition(arr, start, end);

//     quickSort(arr, start, p - 1);

//     quickSort(arr, p + 1, end);
// }

// int main()
// {

//     int arr[] = {9, 3, 4, 2, 1, 8};
//     int n = 6;     

//     quickSort(arr, 0, n - 1);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//  
//     return 0;
// }

// Question 2

// #include <bits/stdc++.h>
// using namespace std;

// void Distinct(int arr[], int n)
// {

//     for (int i = 0; i < n; i++)

//     {

//         int j;

//         for (j = 0; j < i; j++)

//             if (arr[i] == arr[j])

//                 break;

//         if (i == j)

//             cout << arr[i] << " ";
//     }
// }

// int main()
// {

//     int arr[] = {4, 4, 5, 6, 2, 3, 2, 1};

//     int n = sizeof(arr) / sizeof(arr[0]);

//     Distinct(arr, n);

//     return 0;
// }

// Question 3
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, k;
    cout << "enter N,M,K" << endl;
    cin >> n >> m >> k;
    int a[n], b[m];
    int arr[m + n];
    cout << "enter first ordered array" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "enter second ordered array" << endl;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        arr[i] = a[i];
    for (int i = n; i < m + n; i++)
        arr[i] = b[i - n];
    priority_queue<int> ma;
    for (int i = 0; i < n + m; i++)
    {
        ma.push(arr[i]);
        if (ma.size() > k)
            ma.pop();
    }
    cout << ma.top();
}