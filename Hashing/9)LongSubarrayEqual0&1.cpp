#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[7] = {1, 0, 1, 1, 1, 0, 0};

    for (int i = 0; i < 7; i++)
        if (a[i] == 0)
            a[i] = -1;

    unordered_map<int, int> s;
    int presum = 0;
    int res = 0;
    for (int i = 0; i < 7; i++)
    {
        presum += a[i];
        if (presum == 0)
            res = i + 1;
        if (s.find(presum) == s.end())
            s.insert({presum, i});

        if (s.find(presum) != s.end())
            res = max(res, i - s[presum]);
    }
    cout << res;

    return 0;
}