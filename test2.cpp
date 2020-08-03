#include <bits/stdc++.h>
using namespace std;

int main()
{

    int temp, dis = 2;

    int a[5] = {1, 2, 3, 4, 5};

    int sum = 3;
    temp = sum;
    for (int i = 0; i + dis < 5; i++)
    {
        sum = sum - a[i] + a[i + dis];
        temp = sum > temp ? sum : temp;
    }
    cout << temp;
    return 0;
}

