#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[7] = {2, 3, 10, 6, 4, 8, 1};
    int res = a[1] - a[0], minval = a[0];

    for (int i = 1; i < 7; i++)
    {
        res = max(res, a[i] - minval);
        minval = min(minval, a[i]);
    }

    cout << res;

    return 0;
}