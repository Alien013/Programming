#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int total_coins, int sum)
{
    if (sum == 0)
        return 0;

    int res = INT_MAX;
    for (int i = 0; i < total_coins; i++)
    {
        if (coins[i] <= sum)
        {
            int sub_res = 1 + minCoins(coins, total_coins, sum - coins[i]);

            if (sub_res < res)
                res = sub_res;
        }
    }
    return res;
}
int main()
{
    int total_coins;
    cin >> total_coins;

    int coins[total_coins];

    for (int i = 0; i < total_coins; i++)
    {
        cin >> coins[i];
    }

    for (int i = 0; i < total_coins; i++)
    {
        cout << coins[i] << " ";
    }

    int sum;
    cin >> sum;
    cout << minCoins(coins, total_coins, sum);
}