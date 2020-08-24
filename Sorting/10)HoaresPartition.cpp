#include <bits/stdc++.h>
using namespace std;

int hoares(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);

        do
        {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
            return j;

        swap(a[i], a[j]);
    }
}
int main()
{
    int a[8] = {5, 3, 8, 4, 2, 7, 1, 10}, n = 8, val;
    val = hoares(a, 0, 7);
    cout << val << ' ';

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}
