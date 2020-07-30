#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 7, a[7] = {7, 10, 4, 10, 6, 5, 2};
    int current_leader = a[n - 1];
    cout << current_leader << ' ';
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > current_leader)
        {
            current_leader = a[i];
            cout << current_leader << ' ';
        }
    }

    return 0;
}