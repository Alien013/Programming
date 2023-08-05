#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,ans[32];
    cin >>n;
    int res;
    for(int i=0;i<31;i++) {
        res=pow(2,i);
        if(res==n)
        cout<<"true"<<endl;
    }

    // for(int i=0;i<31;i++) {
    //     ans[i]=pow(2,i);
    // }
    // for(int i=0;i<31;i++) {
    //     if(ans[i]==n){
    //     cout<<"true"<<endl;
    //     }
    //     else {
    //     cout<<"False"<<endl;
    //     }
    // }
    
    return 0;
}