#include <bits/stdc++.h>
using namespace std;

int main()
{

    int r = 4, c = 4, a[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    if (r == 1)
    {
        for (int i = 0; i < c; i++)
        {
            cout << a[0][i] << ' ';
        }
    }
    else if (c == 1)
    {
        for (int i = 0; i < r; i++)
        {
            cout << a[i][0] << ' ';
        }
    }
    else
    {
        for (int i = 0; i < c; i++)
        {
            cout << a[0][i] << ' ';
        }
        for (int i = 1; i < r; i++)
        {
            cout << a[i][c - 1] << ' ';
        }
        for (int i = c - 2; i >= 0; i--)
        {
            cout << a[r - 1][i] << ' ';
        }
        for (int i = r - 2; i >= 1; i--)
        {
            cout << a[i][0] << ' ';
        }
    }

    return 0;
}