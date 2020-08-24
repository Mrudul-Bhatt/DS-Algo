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

int hoares(int b[], int l, int h)
{
    int pivot = b[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (b[i] < pivot);

        do
        {
            j--;
        } while (b[j] > pivot);

        if (i >= j)
            return j;

        swap(b[i], b[j]);
    }
}

void qSortLomuto(int a[], int l, int h)
{
    if (l < h)
    {
        int p = lomuto(a, l, h);
        qSortLomuto(a, l, p - 1);
        qSortLomuto(a, p + 1, h);
    }
}

void qSortHoares(int b[], int l, int h)
{
    if (l < h)
    {
        int p = hoares(b, l, h);
        qSortHoares(b, l, p);
        qSortHoares(b, p + 1, h);
    }
}

void qSortL_TailCallElminate(int a[], int l, int h)
{

begin:
    if (l < h)
    {
        int p = lomuto(a, l, h);
        qSortL_TailCallElminate(a, l, p - 1);
        l = p + 1;
        goto begin;
    }
}

void qSortH_TailCallElminate(int b[], int l, int h)
{

begin:
    if (l < h)
    {
        int p = lomuto(b, l, h);
        qSortL_TailCallElminate(b, l, p);
        l = p + 1;
        goto begin;
    }
}

int main()
{
    int a[7] = {10, 80, 30, 90, 40, 50, 70}, b[8] = {5, 3, 8, 4, 2, 7, 1, 10}, n = 7, m = 8;
    qSortLomuto(a, 0, 6);
    qSortHoares(b, 0, 7);
    qSortL_TailCallElminate(a, 0, 6);
    qSortH_TailCallElminate(b, 0, 7);

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    for (int i = 0; i < m; i++)
        cout << b[i] << ' ';

    return 0;
}
