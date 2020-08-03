#include <bits/stdc++.h>
using namespace std;

int main()
{

    int r = 4, c = 4, a[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    int left = 0, right = c - 1, top = 0, bottom = r - 1;

    while (left <= right && top <= bottom)
    {
        //top row
        for (int i = left; i <= right; i++)
        {
            cout << a[top][i] << ' ';
        }
        top++;
        //right column
        for (int i = top; i <= bottom; i++)
        {
            cout << a[i][right] << ' ';
        }
        right--;
        //bottom row reverse order
        if (top <= bottom)
        {

            for (int i = right; i >= left; i--)
            {
                cout << a[bottom][i] << ' ';
            }
            bottom--;
        }
        //left cloumn reverse order
        if (left <= right)
        {

            for (int i = bottom; i >= top; i--)
            {
                cout << a[i][left] << ' ';
            }
            left++;
        }
    }

    return 0;
}