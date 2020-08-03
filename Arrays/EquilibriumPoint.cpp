#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[7] = {-7, 1, 5, 2, -4, 3, 0};
    int i, left_sum = 0, sum = 0;
    for (i = 0; i < 7; i++)
        sum += a[i];
    for (i = 0; i < 7; i++)
    {
        if (left_sum == sum - a[i])
            break;
        left_sum += a[i];
        sum -= a[i];
    }
    i = i == 7 ? -1 : i;
    cout << i;

    return 0;
}