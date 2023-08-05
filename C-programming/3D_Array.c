#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int m,l,n; 
    scanf("%d",&l);
    scanf("%d",&m);
    scanf("%d",&n);
    int arr[l][m][n];
    printf("Enter the Elements in array\n");
    for(int i=0;i<l;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<n;k++) {
            scanf("%d",&arr[i][j][k]);
            }
        }
    }
    for(int i=0;i<l;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<n;k++) {
            printf("%d ",arr[i][j][k]);
            }
        }
    }
    return 0;
}