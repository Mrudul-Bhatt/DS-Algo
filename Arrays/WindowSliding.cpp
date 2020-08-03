#include <bits/stdc++.h>
using namespace std;

int main()
{

    bool exists = false;
    int sum = 33, a[6] = {1, 4, 20, 3, 10, 5};
    int current_sum = a[0], start = 0;
    for (int i = 1; i < 6; i++)
    {
        while (current_sum > sum && start < i - 1)
        {
            current_sum -= a[start];
            start++;
        }
        if (current_sum == sum)
        {
            exists = true;
            break;
        }
        if (i < 6)
            current_sum += a[i];
    }
    exists = current_sum == sum;

    cout << exists;

    return 0;
}