#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Add(int arr[],int n) {
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
        return sum;
}
int main() {
    int n,*p;
    printf("Enter the total number of elements in array\n");
    scanf("%d",&n);
    int arr[n];
    for(p=arr;p<=arr+n-1;p++) {
        scanf("%d",p);
    }
    printf("Original array entered:\n");
    for(p=arr;p<=arr+n-1;p++) {
        printf("%d ",*p);
    }
    // printf("\nArray in reverse order:\n");
    // for(p=arr+n-1;p>=arr;p--) {
    //     printf("%d ",*p);
    // }
    int len=sizeof(arr)/sizeof(arr[0]);

    printf("\nSum of elements is: %d ",Add(arr,len));
    
    return 0;
}