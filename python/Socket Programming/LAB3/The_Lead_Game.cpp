#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    // int arr[n];
    int ans, a, b, c = 0, d = 0, mx = INT_MIN, p;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        ans = c+a-b-d;

        if (ans < 0){
            if (mx < -ans){
                mx = -ans;
                p = 2;
                // cout << a << " " << b << " " << c << " " << d << " " << ans << " " << mx << "\n";
            }
        }
        else{
            if (mx < ans){
                mx = ans;
                p = 1;
                // cout << a << " " << b << " " << c << " " << d << " " << ans << " " << mx << "\n";
            }
        }

        c = c+a;
        d = d+b;
    }
    
    cout << p << " " << mx << "\n";
    
    return 0;
}
