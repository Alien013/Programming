#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> worth(n), fi(n);

    for (int i = 0; i < n; i++)
        cin >> worth[i] >> fi[i];

    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int nottake = worth[i - 1];
        int take = dp[i - 1] + worth[i - 1];
        if (i - fi[i] >= 0)
            nottake = worth[i] + dp[i - fi[i] - 1];
        dp[i] = max(take, nottake);
    }
    cout << dp[n] << "\n";
    return 0;
}