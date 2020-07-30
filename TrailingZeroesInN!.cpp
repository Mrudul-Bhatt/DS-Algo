#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 10, count = 0;

    for (int i = 1;; i++)
    {

        if (floor(n / pow(5, i)) == 0)
        {
            break;
        }
        else
        {
            count += floor(n / pow(5, i));
        }
    }

    cout << count;

    return 0;
}