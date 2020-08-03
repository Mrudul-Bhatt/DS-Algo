#include <bits/stdc++.h>
using namespace std;

int maxOccured(int L[], int R[], int n, int maxx)
{

    vector<int> a;
    for (int i = 0; i < maxx + 10; i++)
    {
        a.push_back(0);
    }
    for (int i = 0; i < n; i++)
    {
        a[L[i]]++;
        a[R[i] + 1]--;
    }
    int max = a[0], result = 0;
    for (int i = 1; i < maxx + 10; i++)
    {
        a[i] += a[i - 1];
        if (max < a[i])
        {
            max = a[i];
            result = i;
        }
    }
    return result;
}