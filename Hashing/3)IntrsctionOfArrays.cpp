#include <bits/stdc++.h>
using namespace std;

int main()
{

    int res = 0, a[7] = {10, 15, 20, 15, 30, 30, 5}, b[4] = {30, 5, 30, 80};
    unordered_set<int> s;
    for (int i = 0; i < 7; i++)
        s.insert(a[i]);
    for (int i = 0; i < 4; i++)
    {
        if (s.find(b[i]) != s.end())
        {
            res++;
            s.erase(b[i]);
        }
    }

    cout << res;

    return 0;
}