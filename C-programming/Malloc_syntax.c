#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, *ptr;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(1);
    }
    printf("Enter elements: \n");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
    }
    for (i = 0; i < n; ++i)
    {
        printf("%d ", *(ptr + i));
    }
    return 0;
}