#include <bits/stdc++.h>
using namespace std;

int reverse(int arr[], int low, int high)
{

    int temp = 0;
    while (low < high)
    {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }

    return arr[5];
}

int main()
{

    int d = 2, n = 5, arr[5] = {1, 2, 3, 4, 5};
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}