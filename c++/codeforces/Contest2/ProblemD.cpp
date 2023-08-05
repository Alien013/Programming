#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void Split()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<char, ll> m1, m2;
    vector<ll> v1(n, 0), v2(n, 0);
    v1[0] = 1;
    m1[s[0]]++;
    for (ll i = 0; i < n; i++)
    {
        if (m1.find(s[i]) == m1.end())
            v1[i] = 1 + v1[i - 1];
        else
            v1[i] = v1[i - 1];
        m1[s[i]]++;
    }
    v2[n - 1] = 1;
    m2[s[n - 1]]++;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (m2.find(s[i]) == m2.end())
            v2[i] = 1 + v2[i + 1];
        else
            v2[i] = v2[i + 1];
        m2[s[i]]++;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, v1[i] + v2[i]);
    }
    if (ans > n)
    {
        ans = n;
    }
    cout << ans<<endl;
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
        Split();
    }

    return 0;
}