#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[7] = {0, 1, 1, 0, 1, 1, 1};
    int current, result = 0;

    for (int i = 0; i < 7; i++)
    {
        if (a[i] != 1)
            current = 0;
        else
        {
            current++;
            result = max(result, current);
        }
    }
    cout << result;

    return 0;
}