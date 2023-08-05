#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
int factorial(int n)
{
    int product = 1;
    if (n == 0 || n == 1)
    {
        return 1;
        // count++;
    }
    else
    {
        product = n * factorial(n - 1);
        // count++;
    }
    return product;
}
int iterative(int n)
{
    int product = 1;
    if (n == 0 || n == 1)
    {
        return 1;
        // count++;
    }
    else
    {
        while (n != 1)
        {
            product = n * product;
            n--;
        }
        return product;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int fact = factorial(n);

    printf("%d", fact);

    int fact1 = iterative(n);
    printf("\n%d", fact1);
    
    // count++;
    // printf("\nNo. of steps for result is %d", count);
    return 0;
}