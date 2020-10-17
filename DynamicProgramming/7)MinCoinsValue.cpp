#include <bits/stdc++.h>
using namespace std;

int getMin(int coins[], int n, int val)
{
    if (val == 0)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= val)
        {
            int sub_res = getMin(coins, n, val - coins[i]);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}

int dp(int coins[], int n, int val)
{
    int dp[val + 1];
    dp[0] = 0;
    for (int i = 1; i <= val; i++)
        dp[i] = INT_MAX;
    for (int i = 1; i <= val; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX)
                    dp[i] = min(dp[i], sub_res + 1);
            }
        }
    }
    return dp[val];
}

int main()
{
    int n = 3, coins[n] = {3, 4, 1}, val = 5;
    cout << getMin(coins, n, val) << " ";
    cout << dp(coins, n, val) << " ";
}