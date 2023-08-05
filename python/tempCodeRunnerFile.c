#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Fact(int arr[],int size) {
    int fact=1
    for(int i=size;i>0;i--) {

        if(arr[i]==0 || arr[i]==1) {
            return 1;
        }

        else {
            fact= arr[i]*(--arr[i]);
        }
    }
    Sort(arr,size);
}

void Sort(int arr[],int size) {
    int temp[size];
    for(int i=0;i<size;i++) {
        if(arr[i]<arr[i+1]) {
            temp[i]=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp[i];
        }
    }
}
int main() {
    int n;
    printf("Enter the number of elements of an array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array \n");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<n;j++) {
        print("%d ",arr[i]);
    }
    Fact(arr,n);

    return 0;
}