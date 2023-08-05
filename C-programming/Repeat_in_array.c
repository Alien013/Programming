#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int arr[10]={1,1,2,3,4,5,6,7,8,9};
    int n,rem;
    while(n>0) {
        rem=n%10;
        if(arr[rem] == 1)
        break;
        arr[rem=1];
        n/=10;
    }
    if(n>0)
    printf("yes");
    else
    printf("No");
    return 0;
}