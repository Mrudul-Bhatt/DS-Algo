#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            cout << arr[j] << ' ';
        }
        cout << endl;
        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;
}
