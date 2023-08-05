#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int rows,col; 
    printf("Ente number of rows in array\n");
    scanf("%d",&rows);
    printf("Ente number of col in array\n");
    scanf("%d",&col);
    int arr[rows][col];
    printf("Enter the Elements in array\n");
    for(int i=0;i<rows;i++) {
        for(int j=0;j<col;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<col;j++) {
            printf("%d ",arr[i][j]);
        }
    }
    return 0;
}