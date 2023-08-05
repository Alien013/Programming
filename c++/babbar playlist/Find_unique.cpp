#include <iostream>
using namespace std;

int findUnique(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
        ans ^= arr[i];
    return ans;
}

void createArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int array[10];

    createArray(array, n);
    printArray(array, n);

    cout << findUnique(array, n) << endl;

    return 0;
}