#include <bits/stdc++.h>
using namespace std;

void sort2types(int a[], int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < 0);
        do
        {
            j--;
        } while (a[j] >= 0);
        if (i >= j)
            return;
        swap(a[i], a[j]);
    }
}

int main()
{
    int a[7] = {-12, 10, -10, 16, 90, -50, 70}, n = 7;
    sort2types(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}
