#include <bits/stdc++.h>
using namespace std;
#define ll long long
void Append() {
    ll n;
    cin >>n;
    string s;
    cin>>s;
    ll a=0,b=n-1;
    ll count=n;
    while(a<=b){
        if ((s[a] == '1' && s[b] == '0') or (s[a] == '0' && s[b] == '1')) {
            count = count-2;
            a++;
            b--;
        }
        else {
        cout<<count<< endl;
        return;
        }
    }
    cout<<count<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--) {
        Append();
    }

    return 0;
}