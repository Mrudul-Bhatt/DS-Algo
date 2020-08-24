#include <bits/stdc++.h>
using namespace std;

//Merge function of merge sort
void mergeFunc(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + i + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

//Merge sort algorithm (Driver Function)
void mergeSortFunc(int arr[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSortFunc(arr, l, m);
        mergeSortFunc(arr, m + 1, r);
        mergeFunc(arr, l, m, r);
    }
}

int main()
{
    int arr[5] = {12, 11, 13, 5, 6}, n = 5;
    mergeSortFunc(arr, 0, 4);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;
}
