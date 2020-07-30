#include <bits/stdc++.h>
using namespace std;

int main()
{

    int low = 0, high = 4, temp = 0, arr[5] = {1, 2, 3, 4, 5};
    while (low < high)
    {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}