#include <bits/stdc++.h>
using namespace std;

int getCount(int coin[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    int res = getCount(coin, n - 1, sum);
    if (coin[n - 1] <= sum)
        res = res + getCount(coin, n, sum - coin[n - 1]);
    return res;
}
int dpfunc(int coin[], int n, int sum)
{
    int dp[sum + 1][n + 1];
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= sum; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (coin[j - 1] <= i)
                dp[i][j] += dp[i - coin[j - 1]][j];
        }
    }
    return dp[sum][n];
}

int main()
{
    int coin[] = {2, 5, 3, 6}, n = 4, sum = 10;
    cout << getCount(coin, n, sum) << " ";
    cout << dpfunc(coin, n, sum) << " ";
}