#include <iostream>
using namespace std;

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

void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
            swap(arr[i], arr[i + 1]);
    }
}

int main()
{
    int n;
    cin >> n;
    int array[10];

    createArray(array, n);
    printArray(array, n);

    swapAlternate(array, n);
    printArray(array, n);

    // int even[8] = {5, 2, 9, 7, 4, 6, 1, 0};
    // int odd[5] = {2, 1, 4, 3, 5};

    // swapAlternate(even, 8);
    // printArray(even, 8);

    // swapAlternate(odd, 5);
    // printArray(odd, 5);

    return 0;
}