#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 5
int main() {
    // // int n;
    // // printf("Enter the number of total elements in array\n");
    // // scanf("%d",&n);
    // int arr[n];
    // for(int i=0;i<n;i++) {
    //     // printf("Enter the %d elements:\n",i+1);
    //     scanf("%d",&arr[i]);
    // }
    // for(int i=0;i<n;i++) {
    //     printf("%d ",arr[i]);
    // }
    // // Reverse an array
    // printf("\nReverse array\n");
    // for(int i=n-1;i>=0;i--) {
    //     printf("%d ",arr[i]);
    // }

    // Check repeated digits
    int seen[n]={0};
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
    while(num>0) {
        int rem = num%10;
        if(seen[rem] == 1)
        break;
        seen[rem]=1;
        num=num/10;
    }
    if(num>0)
    printf("yes");
    else
    printf("No");
    return 0;
}