#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        for(int i=0;i<n;i++)
        cin >> b[i];

        int maximum=max(a[n-1],b[n-1]);
        int minimum=min(a[n-1],b[n-1]);
        
    }
    return 0;
}