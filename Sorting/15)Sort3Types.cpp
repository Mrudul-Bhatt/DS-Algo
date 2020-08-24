#include <bits/stdc++.h>
using namespace std;

void sort3types(int a[], int n)
{
    int l = 0, h = n - 1, mid = 0;
    while (mid <= h)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[l], a[mid]);
            l++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[h]);
            h--;
            break;
        }
    }
}

int main()
{
    int a[6] = {0, 1, 2, 1, 1, 2}, n = 6;
    sort3types(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}
