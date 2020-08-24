#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[7] = {7, 3, 2, 4, 9, 12, 56}, n = 7, m = 3;
    if (m > n)
        cout << -1;
    sort(a, a + n);
    int res = a[m - 1] - a[0];
    for (int i = 1; (m + i - 1) < n; i++)
        res = min(res, a[m + i - 1] - a[i]);

    cout << res << ' ';

    return 0;
}
