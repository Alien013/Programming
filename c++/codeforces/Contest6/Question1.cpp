#include <bits/stdc++.h>
using namespace std;
void Solution() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++){
        if (v[i] <= i + 1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        Solution();
    }
    return 0;
}
