#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, p[N];
string s, t;

void Manacher(string &s)
{
    t += '$';
    t += '#';
    for (int i = 0; i < s.size(); i++)
    {
        t += s[i];
        t += '#';
    }
    int mx = 0, id;
    for (int i = 1; i < t.size(); i++)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]])
            p[i]++;
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
    }
}

int main()
{
    cin >> s;
    n = s.size();
    Manacher(s);
    int ans = 0;
    for (int i = n + 2; i <= 2 * n + 1; i++)
    {
        if (p[i] == i - n - 1)
        {
            ans = max(ans, p[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
