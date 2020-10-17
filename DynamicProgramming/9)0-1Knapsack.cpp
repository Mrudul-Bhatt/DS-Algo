#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);
    else
        return max(knapsack(W, wt, val, n - 1), val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1));
}
int dp(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
        }
    }
    return dp[n][W];
}

int main()
{
    int n = 4, val[n] = {10, 40, 30, 50}, wt[n] = {5, 4, 6, 3}, W = 10;
    cout << knapsack(W, wt, val, n) << " ";
    cout << dp(W, wt, val, n) << " ";
}