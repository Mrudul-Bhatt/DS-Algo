#include <bits/stdc++.h>
using namespace std;

//Merge function of merge sort
int mergeFunc(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + i + 1];
    int i = 0, j = 0, k = l, res = 0;
    while (i < n1 && j < n2)
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
        {
            arr[k++] = right[j++];
            res += n1 - i;
        }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
    return res;
}

//Merge sort algorithm (Driver Function)
int countInversion(int arr[], int l, int r)
{
    int res = 0;
    if (r > l)
    {
        int m = l + (r - l) / 2;
        res += countInversion(arr, l, m);
        res += countInversion(arr, m + 1, r);
        res += mergeFunc(arr, l, m, r);
    }
    return res;
}

int main()
{
    int arr[5] = {12, 11, 13, 5, 6}, n = 5, result;
    result = countInversion(arr, 0, 4);
    cout << result;

    return 0;
}
