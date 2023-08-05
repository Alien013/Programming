#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j=i+1;j<n;j++) {

            if(arr[j]< arr[minIndex])
            minIndex=j;
        }
        swap(arr[minIndex],arr[i]);
    }
}
int main() {
    int arr1[] = {2, 3, 5, 6, 8, 9};
    SelectionSort(arr1, 6);
    return 0;
}