#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int arows, acol, brows,bcol;
    printf("Ente number of rows of matrix A\n");
    scanf("%d", &arows);
    printf("Enter number of col of matrix A\n");
    scanf("%d", &acol);
    int arr1[arows][acol];
    printf("Enter the Elements in array\n");
    for (int i = 0; i < arows; i++)
    {
        for (int j = 0; j < acol; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (int i = 0; i < arows; i++)
    {
        for (int j = 0; j < acol; j++)
        {
            printf("%d ", arr1[i][j]);
        }
    }
    
    printf("\nEnter number of rows of matrix B\n");
    scanf("%d", &brows);
    printf("Enter number of col of matrix B\n");
    scanf("%d", &bcol);
    int arr2[brows][bcol];
    printf("Enter the Elements in array\n");
    for (int i = 0; i < brows; i++)
    {
        for (int j = 0; j < bcol; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (int i = 0; i < brows; i++)
    {
        for (int j = 0; j < bcol; j++)
        {
            printf("%d ", arr2[i][j]);
        }
    }
    if(acol==brows){
    int product[arows][bcol];
    int sum=0;
    for(int i=0;i<arows;i++){
        for(int j=0;j<bcol;j++) {
            for(int k=0;k<brows;k++) {
                sum+=arr1[i][k]*arr2[k][j];
            }
            product[i][j]=sum;
            sum=0;
        }
    }
    printf("Resultant matrix\n");
    for(int i=0;i<arows;i++) {
        for(int j=0;j<bcol;j++) {
            printf("%d ",product[i][j]);
        }
    }
    }
    else 
    printf("Multiplication not possible.");

    return 0;
}