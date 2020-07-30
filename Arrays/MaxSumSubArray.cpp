#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[6] = {-3, 8, -2, 4, -5, 6};
    int result = a[0], maxend = a[0];
    for (int i = 1; i < 6; i++)
    {
        maxend = max(maxend + a[i], a[i]);
        result = max(maxend, result);
    }
    cout << result;
    return 0;
}