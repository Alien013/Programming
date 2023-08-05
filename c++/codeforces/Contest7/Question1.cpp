#include <bits/stdc++.h>
using namespace std;

void Solution()
{
    int n, d;
    string str, res;
    cin >> n >> d >> str;
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if ((str[i] - '0') < d)
        {
            res += '0' + d;
            j = i;
            break;
        }
        res += str[i];
    }
    if (j == -1)
        res += '0' + d;
    else
    {
        for (int i = j; i < n; i++)
            res += str[i];
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        Solution();
}