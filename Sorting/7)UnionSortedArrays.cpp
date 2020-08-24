#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3] = {3, 8, 8}, b[5] = {2, 8, 8, 10, 5}, m = 3, n = 5;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j - 1] == b[j])
        {
            j++;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i] << ' ';
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << ' ';
            j++;
        }
        else
        {
            cout << a[i] << ' ';
            i++;
            j++;
        }
    }
    while (i < m)
    {
        if (i == 0 || a[i - 1] != a[i])
            cout << a[i] << ' ';
        i++;
    }
    while (j < n)
    {
        if (j == 0 || b[j - 1] != a[j])
            cout << b[j] << ' ';
        j++;
    }

    return 0;
}
