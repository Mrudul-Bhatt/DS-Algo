#include <bits/stdc++.h>
using namespace std;

int main()
{

    int sum = 4, a[8] = {8, 3, 1, 5, -6, 6, 2, 2};
    unordered_map<int, int> s;
    int presum = 0;
    int res = 0;
    for (int i = 0; i < 8; i++)
    {
        presum += a[i];
        if (presum == sum)
            res = i + 1;
        if (s.find(presum) == s.end())
            s.insert({presum, i});

        if (s.find(presum - sum) != s.end())
            res = max(res, i - s[presum - sum]);
    }
    cout << res;

    return 0;
}