#include <bits/stdc++.h>
using namespace std;

int sol(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);
    return max(sum - sol(arr, i + 1, j, sum - arr[i]), sum - sol(arr, i, j - 1, sum - arr[j]));
}
int mainSol(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sol(arr, 0, n - 1, sum);
}
int sol2(int arr[], int i, int j)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);
    return max(arr[i] + min(sol2(arr, i + 2, j), sol2(arr, i + 1, j - 1)), arr[j] + min(sol2(arr, i + 1, j - 1), sol2(arr, i, j - 2)));
}
int dp(int arr[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    for (int gap = 3; gap < n; gap = gap + 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n = 4, arr[n] = {20, 5, 4, 6};
    cout << mainSol(arr, n) << " ";
    cout << sol2(arr, 0, n - 1) << " ";
    cout << dp(arr, n) << " ";
}