#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
const int p = 31;

int main()
{
    string s, t;
    cin >> t >> s;
    int S = s.size(), T = t.size();
    vector<int> Hash_T(T + 1, 0);
    vector<int> power(max(S, T), 0);

    power[0] = 1;
    for (int i = 1; i < max(S, T); i++)
        power[i] = (power[i - 1] * p) % mod;

    for (int i = 0; i < T; i++)
    {
        Hash_T[i + 1] = (Hash_T[i] + (t[i] - 'a' + 1) * power[i]) % mod;
    }
    int Hash_S = 0;
    for (int i = 0; i < S; i++)
    {
        Hash_S = (Hash_S + (s[i] - 'a' + 1) * power[i]) % mod;
    }
    int ans = 0;
    for (int i = 0; i + S - 1 < T; i++)
    {
        int curr = (Hash_T[i + S] - Hash_T[i] + mod) % mod;
        if (curr == (Hash_S * power[i]) % mod)
        {
            ans++;
        }
    }
    if (ans == 0)
        cout << "-1" << endl;
    else
        cout << ans << endl;

    return 0;
}