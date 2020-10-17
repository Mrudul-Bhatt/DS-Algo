#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int dp(int n)
{
    int f[n + 1];
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main()
{
    int n = 5;
    cout << fibonacci(n) << " ";
    cout << dp(n) << " ";
}