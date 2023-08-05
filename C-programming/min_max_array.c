#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Min_Max_Array(int arr[],int len,int * min, int *max){
    *min=*max=arr[0];
    for(int i=1;i<len;i++){
        
        if(arr[i]>*max)
        *max=arr[i];

        if(arr[i]<*min)
        *min=arr[i];
    }
}
int *find_Mid(int arr[],int len) {
    return &arr[len/2];
}
int main() {
    int n,len;
    printf("Enter the total number of elememts present in array");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {    
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++) {    
        printf("%d ",arr[i]);
    }
    int min,max;
    len=sizeof(arr)/sizeof(arr[0]);
    Min_Max_Array(arr,len,&min,&max);
    // min=max=arr[0];
    // for(int i=1;i<n;i++) {
    //     if(arr[i]>max)
    //     max=arr[i];
    //     if(arr[i]<min)
    //     min=arr[i];
    // }
    printf("\nminimum element: %d\nMaximum element: %d",min,max);
    int*mid = find_Mid(arr,len);
    printf("\n%d",*mid);
    return 0;
}