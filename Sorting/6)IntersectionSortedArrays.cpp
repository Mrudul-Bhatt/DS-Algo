#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[8] = {3, 5, 10, 10, 10, 15, 15, 20}, b[5] = {5, 10, 10, 15, 30}, m = 8, n = 5;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            cout << a[i] << ' ';
            i++;
            j++;
        }
    }

    return 0;
}
