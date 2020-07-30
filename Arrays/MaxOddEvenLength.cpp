/*
Find max length of even odd subarray

We initialize current and result as 1 as at any point of
time there will be atleast one number which will be even or
odd
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[6] = {5, 10, 20, 6, 3, 8};
    int result = 1, current = 1;
    for (int i = 1; i < 6; i++)
    {
        if ((a[i] % 2 == 0 && a[i - 1] % 2 != 0) || (a[i] % 2 != 0 && a[i - 1] % 2 == 0))
        {
            current++;
            result = max(result, current);
        }
        else
        {
            current = 1;
        }
    }
    cout << result;
    return 0;
}