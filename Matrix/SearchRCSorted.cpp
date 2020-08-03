#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x = 10, r = 4, c = 4, a[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int i = 0, j = c - 1; //selecting top-right element
    while (i < r && j >= 0)
    {
        if (a[i][j] == x)
        {
            cout << "Found";
            return 0;
        }
        else if (a[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout << "Not Found";

    return 0;
}