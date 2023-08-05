
// // Binary Search in C++ using iterative method

// #include <iostream>
// using namespace std;

// int IbinarySearch(int array[], int x, int start, int end)
// {

//     // Repeat until the pointers start and end meet each other
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;

//         if (array[mid] == x)
//             return mid;

//         if (array[mid] < x)
//             start = mid + 1;

//         else
//             end = mid - 1;
//     }

//     return -1;
// }

// int RbinarySearch(int array[], int x, int start, int end)
// {
//     if (end >= start)
//     {
//         int mid = start + (end - start) / 2;

//         // If found at mid, then return it
//         if (array[mid] == x)
//             return mid;

//         // Search the left half
//         if (array[mid] > x)
//             return RbinarySearch(array, x, start, mid - 1);

//         // Search the right half
//         return RbinarySearch(array, x, mid + 1, end);
//     }

//     return -1;
// }

// int main(void)
// {
//     int array[] = {2, 3, 4, 5, 6, 7, 8};
//     int x = 3;
//     int n = sizeof(array) / sizeof(array[0]);
//     int result1 = IbinarySearch(array, x, 0, n - 1);
//     int result2 = RbinarySearch(array, x, 0, n - 1);
//     if (result1 == -1)
//         printf("Not found");
//     else
//         printf("Element is found at index %d\n", result1);
//     if (result2 == -1)
//         printf("Not found\n");
//     else
//         printf("Element is found at index %d\n", result2);
// }

#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    // int mid = (start + end) / 2;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {

        if (arr[mid] == key)
            return mid;

        if (key > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;

        // mid = (start + end) / 2;
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int arr1[] = {2, 3, 5, 6, 8, 9};
    // int arr2[] = {2, 3, 5, 6, 8, 9};

    int index = BinarySearch(arr1, 6, 12);

    cout << "Index of the present key is " << index << endl;

    if (index == -1)
        cout << "key not found" << endl;

    return 0;
}