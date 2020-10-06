#include <bits/stdc++.h>
using namespace std;

int main()
{
    int coin[4] = {10, 2, 1, 5}, n = 4, amount = 52, res = 0;
    sort(coin, coin + n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (coin[i] <= amount)
        {
            int c = floor(amount / coin[i]);
            res = res + c;
            amount = amount - c * coin[i];
        }
        if (amount == 0)
            break;
    }
    cout << res;
    return 0;
}