#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    // int m, n, *p;
    // printf("Enter the number of rows\n");
    // scanf("%d", &m);
    // printf("Enter the number of col\n");
    // scanf("%d", &n);
    // int arr[m][n];
    // for(int i=0;i<m;i++) {
    //     for(int j=0;j<n;j++) {
    //         scanf("%d",&arr[i][j]);
    //     }
    // }
    // for(p=&arr[0][0];p<=&arr[m-1][n-1];p++) {
    //     printf("%d ",*p);
    // }

    // return 0;

    int i,j;
    char a[2][3]={{'a','b','c'},{'d','e','f'}};
    char b[3][2];
    char *p=*b;
    for ( i = 0; i < 2; i++)
    {
        for (j  = 0; j < 3; j++) {
            *(p+2*j+i)=a[i][j];
        }
    }
    for ( i = 0; i < 2; i++)
    {
        for (j  = 0; j < 3; j++) {
         printf("%c ",*(p+2*j+i));
        }
    }
    return 0;
}