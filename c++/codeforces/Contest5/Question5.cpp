#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
const int MAXK = 2005;
const int MOD = 1000000007;

long long dp[MAXN][MAXK];

int main()
{
    int n, k;
    long long m;
    cin >> n >> k >> m;

    // Base case
    for (int j = 0; j < k; j++)
    {
        dp[1][j] = 1;
    }

    // Dynamic programming
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int d = 0; d < k; d++)
            {
                dp[i][j] += dp[i - 1][(j - d + k) % k];
                dp[i][j] %= MOD;
            }
        }
    }

    // Compute final answer
    long long ans = 0;
    for (int j = 0; j < k; j++)
    {
        ans += dp[n][j];
        ans %= MOD;
    }
    ans *= m;
    ans %= MOD;

    cout << ans << endl;
    return 0;
}
