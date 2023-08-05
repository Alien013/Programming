//Author: Manish Kumarrrr//
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI 3.14159265358979323846


int bsrecusive(int low,int high ,int arr[],int key){
    if(low>high)
    return -1;
    int mid=(low+high)/2;
    if(arr[mid]>key){
        return bsrecusive(low,mid-1,arr,key);
    }
    else if(arr[mid]<key)
     return bsrecusive(mid+1,high,arr,key);

     else return mid;
}

int bsiterative(int low,int high ,int arr[],int key){
    while(low<high){
        int mid=(low+high)/2;
        if (arr[mid]>key)
        high=mid-1;
        else if(arr[mid]<key)
        low =mid-1;
        else 
        return mid;
    }
    return -1;
}
int main(){
    int arr[10]={1,1,2,3,4,5,6,7,8};
    cout<<bsiterative(0,9,arr,6)<<"  "<<bsrecusive(0,9,arr,6);

    
    
    return 0;}