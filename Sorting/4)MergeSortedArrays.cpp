#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5] = {5, 6, 11, 12, 13}, b[7] = {1, 3, 5, 7, 15, 32, 45}, n = 5, m = 7;
    int i = 0, j = 0, c[n + m], x = 0;
    while (i < n && j < m)
        if (a[i] < b[j])
            c[x++] = a[i++];
        else
            c[x++] = b[j++];
    while (i < n)
        c[x++] = a[i++];
    while (j < m)
        c[x++] = b[j++];

    for (int i = 0; i < n + m; i++)
        cout << c[i] << ' ';

    return 0;
}
