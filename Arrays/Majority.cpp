#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[7] = {8, 8, 6, 6, 6, 4, 6};
    int count = 1, result = 0;

    for (int i = 1; i < 7; i++)
    {
        if (a[result] == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            result = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < 7; i++)
    {
        if (a[result] == a[i])
            count++;
        if (count < 7 / 2)
            result = -1;
    }
    cout << result;
    return 0;
}