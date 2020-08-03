#include <bits/stdc++.h>
using namespace std;

int main()
{

    int r = 3, c = 3, a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < r; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < c; j++)
            {
                cout << a[i][j] << ' ';
            }
        }
        else
        {
            for (int j = c - 1; j >= 0; j--)
            {
                cout << a[i][j] << ' ';
            }
        }
    }

    return 0;
}