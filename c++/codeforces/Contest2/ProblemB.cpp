#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void Solution() {
    ll n;
    cin >>n;
    string str;
    cin >> str;
    ll x=0,y=0;
    for(auto i:str) {
        if(i=='U') 
        y++;
        if(i=='D') 
        y--;
        if(i=='L') 
        x--;
        if(i=='R') 
        x++;
        if(x==1 && y==1) {

        cout << "YES"<<endl;
        return;
        }
    }
    cout<<"NO"<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        Solution();
    }
    return 0;
}