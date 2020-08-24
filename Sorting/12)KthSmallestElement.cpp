#include <bits/stdc++.h>
using namespace std;

int lomuto(int a[], int l, int h)
{
    int pivot = a[h];
    int j = l - 1;
    for (int i = l; i < h; i++)
    {
        if (a[i] < pivot)
        {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[j + 1], a[h]);
    return j + 1;
}

int kthSmallest(int a[], int n, int k)
{

    int l = 0, h = n - 1;
    while (l <= h)
    {
        int p = lomuto(a, l, h);
        if (p == k - 1)
            return a[p];
        else if (p > k - 1)
            h = h - 1;
        else
            l = l + 1;
    }
    return -1;
}
int main()
{
    int a[7] = {10, 4, 5, 8, 11, 6, 26}, n = 7, k = 5;
    int val = kthSmallest(a, n, k);
    cout << val << ' ';

    return 0;
}
