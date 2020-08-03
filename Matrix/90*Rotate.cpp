/*
transpose then interchange columns
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int temp, n = 4, a[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    int low, high;
    for (int i = 0; i < n; i++)
    {
        low = 0, high = n - 1;
        while (low < high)
        {
            temp = a[low][i];
            a[low][i] = a[high][i];
            a[high][i] = temp;
            low++;
            high--;
        }
    }

    return 0;
}