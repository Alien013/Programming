#include <bits/stdc++.h>
using namespace std;

void printArray(int *A, int *B, int n)
{
    for (int i = 5; i > 0; i--)
    {
        cout << A[i] << " " << B[i] << " ";
    }
    cout << endl;
}
int maximum(int A[], int B[], int n)
{
    int max = INT_MIN;
    int temp;
    for (int i = 0; i < n; i++)
    {
        if (max < B[i])
            max = B[i];
        temp = A[i];
    }
    return max, temp;
}
void CountSort(int *A, int *B, int n)
{
    int i, j;
    int max = maximum(A, B, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i < max + 1; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
    {
        count[B[i]] = count[B[i]] + 1;
    }
    i = 0, j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            B[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int A[] = {101, 102, 103, 104, 105, 106};
    int B[] = {4, 10, 0, 8, 26, 38};
    int n = 6;

    printArray(A, B, n);
    CountSort(A, B, n);
    printArray(A, B, n);

    return 0;
}