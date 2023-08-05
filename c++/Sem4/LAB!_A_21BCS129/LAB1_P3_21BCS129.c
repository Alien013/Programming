#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int M, N;
    scanf("%d", &M);
    int Arr1[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &Arr1[i]);
    }
    printf("sorted array elements of First lists are - \n");

    for (int i = 0; i < M; i++)
    {
        printf("%d ", Arr1[i]);
    }
    printf("\n");
    scanf("%d", &N);
    int Arr2[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Arr1[i]);
    }
    printf("\nsorted array elements of Second lists are - \n");

    for (int i = 0; i < N; i++)
    {
        printf("%d ", Arr1[i]);
    }

    return 0;
}