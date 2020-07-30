

#include <bits/stdc++.h>
using namespace std;

int normal_max_sum(int a[], int n)
{
    // int a[6] = {-3, 8, -2, 4, -5, 6};
    int result = a[0], maxend = a[0];
    for (int i = 1; i < n; i++)
    {
        maxend = max(maxend + a[i], a[i]);
        result = max(maxend, result);
    }

    return result;
}

int main()
{

    int arr_sum = 0, a[6] = {8, -4, 3, -5, 4};
    int normal_max = normal_max_sum(a, 5);
    if (normal_max < 0)
        cout << normal_max;
    for (int i = 0; i < 5; i++)
    {
        arr_sum += a[i];
        a[i] = -a[i];
    }
    int max_circular = arr_sum - (-normal_max_sum(a, 5));
    cout << max(normal_max, max_circular);

    return 0;
}