

#include <iostream>
using namespace std;

int RLS(int arr[], int key, int size)
{
    size = size - 1;
    if (size < 0)
    {
        return -1;
    }
    else if (arr[size] == key)
    {
        return 1;
    }
    else
    {
        return RLS(arr, key, size);
    }
}

int main()
{

    cout << "Enter The Size Of Array:   ";
    int size,index;
    cin >> size;
    int arr[size], key, i;

    // Taking Input In Array
    
    for (int j = 0; j < size; j++)
    {
        cout << "Enter " << j << " Element : ";
        cin >> arr[j];
    }
    // Your Entered Array Is
    
    for (int a = 0; a < size; a++)
    {
        cout << "arr[ " << a << " ]  =  ";
        cout << arr[a] << endl;
    }

    cout << "Enter Key To Search  in Array ";
    cin >> key;
    int result;
    result = RLS(arr, key, size--);
    if (result == 1)
    {
        cout << "Key Found in Array  ";
    }
    else
    {
        cout << "Key NOT Found in Array  ";
    }
    
    //iterative

    for (i = 0; i < 10; i++)
    {
        if (arr[i] == key)
        {
            index = i;
            break;
        }
    }
    cout << "\nFound at Index No." << index;
    cout << endl;
    return 0;
}